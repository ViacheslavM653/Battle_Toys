// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "BattleToysProjectile/BattleToysProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "Kismet/KismetMathLibrary.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Components/AudioComponent.h"

#include "../../../../Engine/Plugins/FX/Niagara/Source/Niagara/Public/NiagaraFunctionLibrary.h"
#include "../../../../Engine/Plugins/FX/Niagara/Source/Niagara/Public/NiagaraComponent.h"



AFriendlyBaseTank::AFriendlyBaseTank()
{
	//Creating Hirarchical Structure
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComponent;
	CapsuleComponent->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	TankPivot = CreateDefaultSubobject<USceneComponent>(TEXT("Tank Pivot"));

	TankPivot->SetupAttachment(CapsuleComponent);
	ForwardRightWheelSensor = CreateDefaultSubobject<USceneComponent>(TEXT("ForwardRight Wheel Sensor"));
	ForwardRightWheelSensor->SetupAttachment(CapsuleComponent);
	ForwardLeftWheelSensor = CreateDefaultSubobject<USceneComponent>(TEXT("ForwardLeft Wheel Sensor"));
	ForwardLeftWheelSensor->SetupAttachment(CapsuleComponent);
	BackwardRightWheelSensor = CreateDefaultSubobject<USceneComponent>(TEXT("BackwardRight Wheel Sensor"));
	BackwardRightWheelSensor->SetupAttachment(CapsuleComponent);
	BackwardLeftWheelSensor = CreateDefaultSubobject<USceneComponent>(TEXT("BackwardLeft Wheel Sensor"));
	BackwardLeftWheelSensor->SetupAttachment(CapsuleComponent);

	TankHullSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Tank Hull SkeletalMesh"));
	TankHullSkeletalMesh->SetupAttachment(TankPivot);

	RightExhaustNPS = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Right Exhaust Niagara PS"));
	RightExhaustNPS->SetupAttachment(TankHullSkeletalMesh);

	LeftExhaustNPS = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Left Exhaust Niagara PS"));
	LeftExhaustNPS->SetupAttachment(TankHullSkeletalMesh);
	
	if (TankIdleSound)
	{
		TankIdleSoundComponent = UGameplayStatics::SpawnSoundAttached(TankIdleSound, RightExhaustNPS);
	}
	if (TankAccelerationSound)
	{
		TankAccelerationSoundComponent = UGameplayStatics::SpawnSoundAttached(TankAccelerationSound, RightExhaustNPS);
	}

	TankLeftTrackMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank Left Track Mesh"));
	TankLeftTrackMesh->SetupAttachment(TankHullSkeletalMesh);

	TankRightTrackMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank Right Track Mesh"));
	TankRightTrackMesh->SetupAttachment(TankHullSkeletalMesh);
	
	TankTowerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank Tower Mesh"));
	TankTowerMesh->SetupAttachment(TankHullSkeletalMesh);

	TankBarrelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tank Barrel Mesh"));
	TankBarrelMesh->SetupAttachment(TankTowerMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TankBarrelMesh);

	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating Pawn Movement Component"));
	
}

void AFriendlyBaseTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AFriendlyBaseTank::Move);
	PlayerInputComponent->BindAxis(TEXT("TurnRight"), this, &AFriendlyBaseTank::Turn);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &AFriendlyBaseTank::Fire);
}

float AFriendlyBaseTank::GetRightWheelsAnimationSpeed()
{
	float RightTrackAnimationSpeed = 0;
	float TankSpeedRate = TankSpeedRateForAnimation;
	float TankTurnRight = TankTurnRightForAnimation;
	
	//Tank not move
	if (TankSpeedRate == 0 && TankTurnRight == 0)
	{
		RightTrackAnimationSpeed = 0;
	}
	//Tank turn right
	if (TankSpeedRate == 0 && TankTurnRight > 0)
	{
		RightTrackAnimationSpeed = 0;
	}
	//Tank turn left
	if (TankSpeedRate == 0 && TankTurnRight < 0)
	{
		RightTrackAnimationSpeed = 1;
	}
	//Tank only move forward
	if (TankSpeedRate > 0 && TankTurnRight == 0)
	{
		RightTrackAnimationSpeed = TankSpeedRate;
	}
	//Tank move forward and turn right
	if (TankSpeedRate > 0 && TankTurnRight > 0)
	{
		RightTrackAnimationSpeed = 0;
	}
	//Tank move forward and turn left
	if (TankSpeedRate > 0 && TankTurnRight < 0)
	{
		RightTrackAnimationSpeed = TankSpeedRate;
	}
	//Tank only move backward
	if (TankSpeedRate < 0 && TankTurnRight == 0)
	{
		RightTrackAnimationSpeed = TankSpeedRate;
	}
	//Tank move backward and turn right
	if (TankSpeedRate < 0 && TankTurnRight < 0)
	{
		RightTrackAnimationSpeed = 0;
	}
	//Tank move backward and turn left
	if (TankSpeedRate < 0 && TankTurnRight > 0)
	{
		RightTrackAnimationSpeed = TankSpeedRate;
	}
			
	RightWheelsAction = RightTrackAnimationSpeed;

	TankTrackRightPosition = TankTrackRightPosition +
		((RightTrackAnimationSpeed * TankWheelAnimationSpeedMultiplier) *
		(UGameplayStatics::GetWorldDeltaSeconds(this) * TankTrackAnimationSpeedMultiplier));
	
	if (RightTankTrackDynamicMaterial)
	{
		RightTankTrackDynamicMaterial->SetScalarParameterValue("SlideValue", TankTrackRightPosition);
	}
	
	return RightTrackAnimationSpeed * TankWheelAnimationSpeedMultiplier;
}

float AFriendlyBaseTank::GetLeftWheelsAnimationSpeed()
{
	float LeftTrackAnimationSpeed = 0;
	float TankSpeedRate = TankSpeedRateForAnimation;
	float TankTurnRight = TankTurnRightForAnimation;
	//Tank not move
	if (TankSpeedRate == 0 && TankTurnRight == 0)
	{
		LeftTrackAnimationSpeed = 0;
	}
	//Tank turn right
	if (TankSpeedRate == 0 && TankTurnRight > 0)
	{
		LeftTrackAnimationSpeed = 1;
	}
	//Tank turn left
	if (TankSpeedRate == 0 && TankTurnRight < 0)
	{
		LeftTrackAnimationSpeed = 0;
	}
	//Tank only move forward
	if (TankSpeedRate > 0 && TankTurnRight == 0)
	{
		LeftTrackAnimationSpeed = TankSpeedRate;
	}
	//Tank move forward and turn right
	if (TankSpeedRate > 0 && TankTurnRight > 0)
	{
		LeftTrackAnimationSpeed = TankSpeedRate;
	}
	//Tank move forward and turn left
	if (TankSpeedRate > 0 && TankTurnRight < 0)
	{
		LeftTrackAnimationSpeed = 0;
	}
	//Tank only move backward
	if (TankSpeedRate < 0 && TankTurnRight == 0)
	{
		LeftTrackAnimationSpeed = TankSpeedRate;
	}
	//Tank move backward and turn right
	if (TankSpeedRate < 0 && TankTurnRight < 0)
	{
		LeftTrackAnimationSpeed = TankSpeedRate;
	}
	//Tank move backward and turn left
	if (TankSpeedRate < 0 && TankTurnRight > 0)
	{
		LeftTrackAnimationSpeed = 0;
	}
	
	LeftWheelsAction = LeftTrackAnimationSpeed;

	TankTrackLeftPosition = TankTrackLeftPosition +
		((LeftTrackAnimationSpeed * TankWheelAnimationSpeedMultiplier) *
		(UGameplayStatics::GetWorldDeltaSeconds(this) * TankTrackAnimationSpeedMultiplier));

	if (LeftTankTrackDynamicMaterial)
	{
		LeftTankTrackDynamicMaterial->SetScalarParameterValue("SlideValue", TankTrackLeftPosition);
	}

	return LeftTrackAnimationSpeed * TankWheelAnimationSpeedMultiplier;
}

void AFriendlyBaseTank::Move(float AxisValue)
{
	MoveForwardValue = AxisValue;
	AddMovementInput(FindMovementInputVector(AxisValue) * AxisValue);

}

FVector AFriendlyBaseTank::FindMovementInputVector(float AxisValue)
{
	//Tracing to ground

	FVector Start = TankPivot->GetComponentLocation();
	float DepthTracingValue = 100;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	FHitResult OutHit = GetTracingResultByVisibility(Start, DepthTracingValue);

	//Find Ground Point
	FVector HitPoint = OutHit.ImpactPoint;

	//Find	Direction vector
	FVector ActorForwardVector = GetActorForwardVector();
	FVector ProjectionNormal = GetActorRightVector();
	FVector ProjectedHitNormal = FVector::VectorPlaneProject(OutHit.ImpactNormal, ProjectionNormal);
	FVector DirectionVector = ProjectedHitNormal.Cross(-ProjectionNormal);

	//Prepare CorrectionValue for DirectionVector
	FVector TankPivotLocation = TankPivot->GetComponentLocation();
	float HitDistance = FVector::Distance(TankPivotLocation, HitPoint);
	FVector DirectionVectorAbsolute = DirectionVector.GetAbs();

	if (DirectionVectorAbsolute.Z != 0 && HitDistance != 0)
	{
		float MaximumCompensation = (0.98 - DirectionVectorAbsolute.Z);
		//UE_LOG(LogTemp, Warning, TEXT("MaximumCompensation: %f"), MaximumCompensation);
		float CorrectionValue = (HitDistance / DepthTracingValue) * MaximumCompensation;
		//UE_LOG(LogTemp, Warning, TEXT("CorrectionValue: %f"), CorrectionValue);
		if (AxisValue > 0)
		{
			DirectionVector.Z = DirectionVector.Z - CorrectionValue;
		}
		if (AxisValue < 0)
		{
			DirectionVector.Z = DirectionVector.Z + CorrectionValue;
		}

	}

	FVector MovementInputVector = DirectionVector;
	return MovementInputVector;
}

void AFriendlyBaseTank::Turn(float AxisValue)
{
	//UE_LOG(LogTemp, Warning, TEXT("TurnRight Axis Value: %f"), AxisValue);

	FRotator DeltaRotation = FRotator::ZeroRotator;
	// Yaw = Value * DeltaTime * TurnRate;
	float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
	if (MoveForwardValue > 0)
	{
		DeltaRotation.Yaw = AxisValue * DeltaTime * TurnRate;
		AddActorLocalRotation(DeltaRotation, true);
	}
	if (MoveForwardValue < 0)
	{
		DeltaRotation.Yaw = -AxisValue * DeltaTime * TurnRate;
		AddActorLocalRotation(DeltaRotation, true);
	}
	if (MoveForwardValue == 0)
	{
		DeltaRotation.Yaw = AxisValue * DeltaTime * TurnRate;
		AddActorLocalRotation(DeltaRotation, true);
	}
}

void AFriendlyBaseTank::Fire()
{
	FVector Location = ProjectileSpawnPoint->GetComponentLocation();
	FRotator Rotation = ProjectileSpawnPoint->GetComponentRotation();
	if (ProjectileClass)
	{
		ABattleToysProjectile* Projectile = GetWorld()->SpawnActor<ABattleToysProjectile>(ABasePawn::ProjectileClass, Location, Rotation);
		Projectile->SetOwner(this);
	}


}

void AFriendlyBaseTank::BeginPlay()
{
	Super::BeginPlay();
	
	CreateDynamicMaterialsInstancesForTankTracks();

	CreateExhaustSoundComponents();
}

void AFriendlyBaseTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	SetupTankOnGround();
		
	StorageActorRotation(TankRotationHistoryDepth);

	GetTankSpeedRateForAnimation();

	GetTankTurnRightForAnimation();

	PlayExhaustSound();

	SetTankExhaustNiagaraParticles(ExhaustIdleVelocitySpeed, ExhaustIdleSpawnRate, ExhaustMaxVelocitySpeed, ExhaustMaxSpawnRate);
		
}

void AFriendlyBaseTank::TurnTankTowerToEnemy(FVector& LookAtTarget)
{
	FVector ToTarget = LookAtTarget - TankPivot->GetComponentLocation();
	FRotator TowerRelativeRotation = TankTowerMesh->GetRelativeRotation();;
	FVector ToTargetProjectedXY = FVector::VectorPlaneProject(ToTarget, FVector(0, 0, 1));
	FRotator ActorRotation = GetActorRotation();
	FRotator TargetDeltaRotator = ToTargetProjectedXY.Rotation();
	TargetDeltaRotator.Yaw = TargetDeltaRotator.Yaw - ActorRotation.Yaw;
	TargetDeltaRotator = FMath::RInterpTo(
		TowerRelativeRotation,
		TargetDeltaRotator,
		UGameplayStatics::GetWorldDeltaSeconds(this),
		TurnTankTowerInterpolationSpeed
	);
		
	TankTowerMesh->SetRelativeRotation(TargetDeltaRotator.Quaternion());
	
}

void AFriendlyBaseTank::SetupTankOnGround()
{
	float DepthTracingValue = 300.f;

	//Caclulate Traceing Data
	FVector ForwardRightWheelSensorLocation = ForwardRightWheelSensor->GetComponentLocation();
	FHitResult  ForwardRightWheelSensorOutHit = GetTracingResultByVisibility(
		ForwardRightWheelSensorLocation,
		DepthTracingValue
	);

	float ForwardRightWheelSensorPitch = GetPitchFromHitNormal(ForwardRightWheelSensorOutHit);
	float ForwardRightWheelSensorRoll = GetRollFromHitNormal(ForwardRightWheelSensorOutHit);


	FVector ForwardLeftWheelSensorLocation = ForwardLeftWheelSensor->GetComponentLocation();
	FHitResult  ForwardLeftWheelSensorOutHit = GetTracingResultByVisibility(
		ForwardLeftWheelSensorLocation,
		DepthTracingValue
	);

	float ForwardLeftWheelSensorPitch = GetPitchFromHitNormal(ForwardLeftWheelSensorOutHit);
	float ForwardLeftWheelSensorRoll = GetRollFromHitNormal(ForwardLeftWheelSensorOutHit);

	FVector BackwardRightWheelSensorLocation = BackwardRightWheelSensor->GetComponentLocation();
	FHitResult  BackwardRightWheelSensorOutHit = GetTracingResultByVisibility(
		BackwardRightWheelSensorLocation,
		DepthTracingValue
	);

	float BackwardRightWheelSensorPitch = GetPitchFromHitNormal(BackwardRightWheelSensorOutHit);
	float BackwardRightWheelSensorRoll = GetRollFromHitNormal(BackwardRightWheelSensorOutHit);

	FVector BackwardLeftWheelSensorLocation = BackwardLeftWheelSensor->GetComponentLocation();
	FHitResult  BackwardLeftWheelSensorOutHit = GetTracingResultByVisibility(
		BackwardLeftWheelSensorLocation,
		DepthTracingValue
	);

	float BackwardLeftWheelSensorPitch = GetPitchFromHitNormal(BackwardLeftWheelSensorOutHit);
	float BackwardLeftWheelSensorRoll = GetRollFromHitNormal(BackwardLeftWheelSensorOutHit);

	//Get average Pitch
	float AveragePitch =
		(ForwardRightWheelSensorPitch +
			ForwardLeftWheelSensorPitch +
			BackwardRightWheelSensorPitch +
			BackwardLeftWheelSensorPitch) / 4
		;
	//Get average Roll
	float AverageRoll =
		(ForwardRightWheelSensorRoll +
			ForwardLeftWheelSensorRoll +
			BackwardRightWheelSensorRoll +
			BackwardLeftWheelSensorRoll) / 4
		;
		
	FRotator ActorRotation = GetActorRotation();
	FRotator TankPivotRelativeRotation = TankPivot->GetRelativeRotation();
	
	FRotator NeedDeltaRotator = FRotator(AveragePitch, 0.f, AverageRoll);
	NeedDeltaRotator.Pitch = NeedDeltaRotator.Pitch - ActorRotation.Pitch;
	NeedDeltaRotator.Roll = NeedDeltaRotator.Roll - ActorRotation.Roll;
	FRotator NewRotation = NeedDeltaRotator;
	
	NewRotation = FMath::RInterpTo(
		TankPivotRelativeRotation,
		NewRotation,
		UGameplayStatics::GetWorldDeltaSeconds(this),
		SuspensionHardness
	);
	
	TankPivot->SetRelativeRotation(NewRotation.Quaternion());
}

float AFriendlyBaseTank::GetPitchFromHitNormal(FHitResult& HitResult)
{
	FVector XZPlaneNormal = GetActorRightVector();
	FVector SensorNormalToXZ = FVector::VectorPlaneProject(HitResult.ImpactNormal, XZPlaneNormal);
	FVector SensorNormalToXZCrossVsRightVector = SensorNormalToXZ.Cross(-XZPlaneNormal);
	FRotator CrossRezultRotator = SensorNormalToXZCrossVsRightVector.Rotation();
	FRotator ActorRotation = GetActorRotation();
	ActorRotation.Pitch = CrossRezultRotator.Pitch;
	FRotator FinalRotator = ActorRotation - GetActorRotation();

	return FinalRotator.Pitch;
}

float AFriendlyBaseTank::GetRollFromHitNormal(FHitResult& HitResult)
{
	FVector YZPlaneNormal = GetActorForwardVector();
	FVector SensorNormalToYZ = FVector::VectorPlaneProject(HitResult.ImpactNormal, YZPlaneNormal);
	FVector SensorNormalToYZCrossVsRightVector = SensorNormalToYZ.Cross(-YZPlaneNormal);
	FRotator CrossRezultRotator = SensorNormalToYZCrossVsRightVector.Rotation();
	FRotator ActorRotation = GetActorRotation();
	ActorRotation.Roll = CrossRezultRotator.Pitch;
	FRotator FinalRotator = ActorRotation - GetActorRotation();

	return FinalRotator.Roll;
}

FHitResult AFriendlyBaseTank::GetTracingResultByVisibility(FVector& StartLocation, float& DepthTracingValue)
{
	FHitResult OutHit;
	FVector Start = StartLocation;
	FVector DeltaLength = FVector::ZeroVector;
	DeltaLength.Z = -DepthTracingValue;
	FVector End = Start + DeltaLength;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	//DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECollisionChannel::ECC_Visibility, Params);

	return OutHit;
}

void AFriendlyBaseTank::GetTankSpeedRateForAnimation()
{
	// Find speed rate
	FVector TankActorForwardVector = GetActorForwardVector();
	FVector TankVelocity = this->GetVelocity();
	float TankSpeedValue = TankVelocity.Length();

	float TankSpeedRate = FMath::GetMappedRangeValueUnclamped(
			FVector2D(0.f, MovementComponent->MaxSpeed),
			FVector2D(0.f, 1.f),
			TankSpeedValue
			);
		// Find speed sign
	float TankSpeedSign = TankVelocity.Y * TankActorForwardVector.Y;
	if (TankSpeedSign != 0)
	{
		TankSpeedSign = TankSpeedSign / FMath::Abs(TankSpeedSign);
		TankSpeedRate = TankSpeedRate * TankSpeedSign;
	}
		
	TankSpeedRateForAnimation = TankSpeedRate;
	

}

void AFriendlyBaseTank::StorageActorRotation(int32 StorageDepth)
{
	FVector TankForwardVector = GetActorForwardVector();
	
	for (int32 Cell = (StorageDepth - 1); Cell >= 1; Cell--)
	{
		TankRotationHistoryArray[Cell - 1] = TankRotationHistoryArray[Cell];
	}
	TankRotationHistoryArray[StorageDepth - 1] = TankForwardVector.Rotation();
}

void AFriendlyBaseTank::GetTankTurnRightForAnimation()
{
	FRotator NewTankForwardRotation = GetActorForwardVector().Rotation();
	//UE_LOG(LogTemp, Warning, TEXT("TankRotationHistoryArray[0]: %s"), TankRotationHistoryArray[0].ToString());
	FRotator DeltaRotation = NewTankForwardRotation - TankRotationHistoryArray[0];

	if (FMath::Abs(DeltaRotation.Yaw) > 180)
	{
		if (NewTankForwardRotation.Yaw > 0)
		{
			DeltaRotation.Yaw = DeltaRotation.Yaw - 360.f;
		}
		if (NewTankForwardRotation.Yaw < 0)
		{
			DeltaRotation.Yaw = DeltaRotation.Yaw + 360.f;
		}
	}
	
	float FinalResult = 0;
	if (DeltaRotation.Yaw == 0)
	{
		FinalResult = 0;
	}
	if (DeltaRotation.Yaw > 0)
	{
		float InputMax = DeltaRotation.Yaw;
		FinalResult = FMath::GetMappedRangeValueUnclamped(FVector2D(0, InputMax), FVector2D(0, 1), DeltaRotation.Yaw);
		
	}
	if (DeltaRotation.Yaw < 0)
	{
		float InputMax = DeltaRotation.Yaw;
		FinalResult = FMath::GetMappedRangeValueUnclamped(FVector2D(0, InputMax), FVector2D(0, -1), DeltaRotation.Yaw);
	}
	
	TankTurnRightForAnimation = FinalResult;
}

void AFriendlyBaseTank::CreateDynamicMaterialsInstancesForTankTracks()
{
	RightTankTrackDynamicMaterial = UMaterialInstanceDynamic::Create(TankRightTrackMesh->GetMaterial(0),this);

	if (RightTankTrackDynamicMaterial)
	{
		TankRightTrackMesh->SetMaterial(0, RightTankTrackDynamicMaterial);
	}
	LeftTankTrackDynamicMaterial = UMaterialInstanceDynamic::Create(TankLeftTrackMesh->GetMaterial(0), this);
	if (LeftTankTrackDynamicMaterial)
	{
		TankLeftTrackMesh->SetMaterial(0, LeftTankTrackDynamicMaterial);
	}
}

void AFriendlyBaseTank::CreateExhaustSoundComponents()
{
	if (!TankAccelerationSoundComponent)
	{
		TankAccelerationSoundComponent = UGameplayStatics::SpawnSoundAttached(TankAccelerationSound, RightExhaustNPS);
		if (TankAccelerationSoundComponent)
		{
			TankAccelerationSoundComponent->FadeIn(2);
		}
	}
	if (!TankIdleSoundComponent)
	{
		TankIdleSoundComponent = UGameplayStatics::SpawnSoundAttached(TankIdleSound, RightExhaustNPS);
		if (TankIdleSoundComponent)
		{
			TankIdleSoundComponent->FadeIn(2);		
		}
	}
}

void AFriendlyBaseTank::SetTankExhaustNiagaraParticles(
	float IdleVelocitySpeed,
	float IdleSpawnRate, 
	float MaxVelocitySpeed, 
	float MaxSpawnRate)
{
	if (RightWheelsAction != 0 || LeftWheelsAction != 0)
	{
		if (RightExhaustNPS)
		{
			RightExhaustNPS->SetNiagaraVariableFloat(FString("MaxVelocitySpeed"), MaxVelocitySpeed);
			RightExhaustNPS->SetNiagaraVariableFloat(FString("SpawnRate"), MaxSpawnRate);
		}
		if (LeftExhaustNPS)
		{
			LeftExhaustNPS->SetNiagaraVariableFloat(FString("MaxVelocitySpeed"), MaxVelocitySpeed);
			LeftExhaustNPS->SetNiagaraVariableFloat(FString("SpawnRate"), MaxSpawnRate);
		}
	
	}
	
	else 
	{
		if (RightExhaustNPS)
		{
			RightExhaustNPS->SetNiagaraVariableFloat(FString("MaxVelocitySpeed"), IdleVelocitySpeed);
			RightExhaustNPS->SetNiagaraVariableFloat(FString("SpawnRate"), IdleSpawnRate);
		}
		if (LeftExhaustNPS)
		{
			LeftExhaustNPS->SetNiagaraVariableFloat(FString("MaxVelocitySpeed"), IdleVelocitySpeed);
			LeftExhaustNPS->SetNiagaraVariableFloat(FString("SpawnRate"), IdleSpawnRate);
		}
	}
}

void AFriendlyBaseTank::PlayExhaustSound()
{
	if (TankIdleSound && TankAccelerationSound)
	{
			
		if (RightWheelsAction != 0 || LeftWheelsAction != 0)
		{
			TankIdleSoundComponent->SetPaused(true);
			TankAccelerationSoundComponent->SetPaused(false);
			//TankAccelerationSoundComponent->FadeIn(2);
			//TankAccelerationSoundComponent->Play();
		}
		else
		{
			TankAccelerationSoundComponent->SetPaused(true);
			TankIdleSoundComponent->SetPaused(false);
			//TankIdleSoundComponent->FadeIn(1);
			//TankIdleSoundComponent->Play();
		}

		
	}
		
}
