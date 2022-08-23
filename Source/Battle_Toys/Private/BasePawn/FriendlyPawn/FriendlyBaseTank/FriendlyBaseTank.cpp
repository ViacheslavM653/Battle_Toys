// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "BattleToysProjectile/BattleToysProjectile.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "Kismet/KismetMathLibrary.h"



#include "BasePawn/EnemyPawn/EnemyPawn.h"



AFriendlyBaseTank::AFriendlyBaseTank()
{
	//Creating Hirarchical Structure
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComponent;
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

/*---------Start------------Temp Block----------------Start------------------*/


void AFriendlyBaseTank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AFriendlyBaseTank::Move);
	PlayerInputComponent->BindAxis(TEXT("TurnRight"), this, &AFriendlyBaseTank::Turn);

	PlayerInputComponent->BindAction(TEXT("Fire"), IE_Pressed, this, &AFriendlyBaseTank::Fire);
}


void AFriendlyBaseTank::Move(float AxisValue)
{

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
	DeltaRotation.Yaw = AxisValue * DeltaTime * TurnRate;
	AddActorLocalRotation(DeltaRotation, true);
}

/*---------End------------Temp Block----------------End------------------*/





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

	SetStartTankPositionByTerrain();

	//TArray<AActor*> TargetTowerCount;
	//UGameplayStatics::GetAllActorsOfClass(this, AEnemyPawn::StaticClass(), TargetTowerCount);

	//FVector LookAtTarget = TargetTowerCount[0]->GetActorLocation();
	//RotateTankTowerToEnemy(LookAtTarget);

}

void AFriendlyBaseTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetupTankOnGround();
		
	StorageActorRotation(TankRotationHistoryDepth);

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
		TurnTankTowerInterpolationSpeed
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


void AFriendlyBaseTank::SetStartTankPositionByTerrain()
{
	FVector StartLocation = TankPivot->GetComponentLocation();
	float DepthTracingValue = 300.f;
	FHitResult OutHit = GetTracingResultByVisibility(StartLocation, DepthTracingValue);
	float CorrectionValue = OutHit.Distance;

	FVector ActorSetupLocation = GetActorLocation();
	ActorSetupLocation.Z = ActorSetupLocation.Z - CorrectionValue * 0.99;
	SetActorLocation(ActorSetupLocation);
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

float AFriendlyBaseTank::GetTankSpeedRateForAnimation()
{
	// Find speed rate
	FVector TankActorForwardVector = this->GetActorForwardVector();
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

	return TankSpeedRate;
}

void AFriendlyBaseTank::StorageActorRotation(int32 StorageDepth)
{
	FVector TankForwardVector = GetActorForwardVector();

	if (CurrentHistoryIterrator > (StorageDepth - 1))
	{
		CurrentHistoryIterrator = 0;
	}

	TankRotationHistoryArray[CurrentHistoryIterrator] = TankForwardVector.Rotation();
	
	CurrentHistoryIterrator += 1;
		
}

float AFriendlyBaseTank::GetTankTurnRightForAnimation()
{
	FRotator NewTankForwardRotation = GetActorForwardVector().Rotation();

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
	return DeltaRotation.Yaw;
}
