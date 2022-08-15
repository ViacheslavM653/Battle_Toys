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
	FVector DirectionVector = ProjectedHitNormal.Cross( - ProjectionNormal);

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

void AFriendlyBaseTank::SetupTankOnGround()
{
	float DepthTracingValue = 300.f;
	
	//Caclulate Traceing Data
	FVector ForwardRightWheelSensorLocation = ForwardRightWheelSensor->GetComponentLocation();
	FHitResult  ForwardRightWheelSensorOutHit = GetTracingResultByVisibility(
		ForwardRightWheelSensorLocation, 
		DepthTracingValue
	);


	/*----------------------Prototype-------------------------------*/
	//Progect ForwardRightWheelSensorOutHit.IpactNormal to XZ Plane

	//FVector XZPlaneNormal = GetActorRightVector();
	//FVector ForwardRightWheelSensorNormalToXZ = FVector::VectorPlaneProject(ForwardRightWheelSensorOutHit.ImpactNormal, XZPlaneNormal);
	//FVector ForwardRightWheelSensorCrossToRightVector = ForwardRightWheelSensorNormalToXZ.Cross(-XZPlaneNormal);
	//UE_LOG(LogTemp, Warning, TEXT("ForwardRightWheelSensorCrossToRightVector.Rotation(): %s"), *ForwardRightWheelSensorCrossToRightVector.Rotation().ToString());
	//FRotator TestPitchRotator = ForwardRightWheelSensorCrossToRightVector.Rotation();
	FRotator ActorRotation = GetActorRotation();
	ActorRotation.Pitch = GetPitchFromHitNormal(ForwardRightWheelSensorOutHit);
	FRotator FinalRotator = ActorRotation - GetActorRotation();
	// Round to 2 sign affter koma

	//float Rounded = FMath::RoundToInt(ActorRotation.Pitch * 100);
	//FinalRotator.Pitch = Rounded / 100;

	UE_LOG(LogTemp, Warning, TEXT("FinalRotator: %s"), *FinalRotator.ToString());

	
	TankPivot->SetRelativeRotation(FinalRotator.Quaternion(),true);
	/*----------------------Prototype END------------------------------*/
	FVector ForwardLeftWheelSensorLocation = ForwardLeftWheelSensor->GetComponentLocation();
	FHitResult  ForwardLeftWheelSensorOutHit = GetTracingResultByVisibility(
		ForwardLeftWheelSensorLocation,
		DepthTracingValue
	);
	FVector BackwardRightWheelSensorLocation = BackwardRightWheelSensor->GetComponentLocation();
	FHitResult  BackwardRightWheelSensorOutHit = GetTracingResultByVisibility(
		BackwardRightWheelSensorLocation,
		DepthTracingValue
	);
	FVector BackwardLeftWheelSensorLocation = BackwardLeftWheelSensor->GetComponentLocation();
	FHitResult  BackwardLeftWheelSensorOutHit = GetTracingResultByVisibility(
		BackwardLeftWheelSensorLocation,
		DepthTracingValue
	);

	// Visualization Search Vector 
	DrawDebugCoordinateSystem(
		GetWorld(),
		TankPivot->GetComponentLocation(),
		ActorRotation,
		200.f
	);


	// Visualization Tracin Data
	DrawDebugCoordinateSystem(
		GetWorld(), 
		ForwardRightWheelSensorOutHit.ImpactPoint,
		ForwardRightWheelSensorOutHit.ImpactNormal.Rotation(),
		70.f
	);
	//UE_LOG(LogTemp, Warning, TEXT("ForwardRightWheelSensorOutHit.ImpactNormal.X: %f"), ForwardRightWheelSensorOutHit.ImpactNormal.X);
	DrawDebugCoordinateSystem(
		GetWorld(), 
		ForwardLeftWheelSensorOutHit.ImpactPoint,
		ForwardLeftWheelSensorOutHit.ImpactNormal.Rotation(),
		70.f
	);
	//UE_LOG(LogTemp, Warning, TEXT("ForwardLeftWheelSensorOutHit.ImpactNormal.X: %f"), ForwardLeftWheelSensorOutHit.ImpactNormal.X);
	DrawDebugCoordinateSystem(
		GetWorld(), 
		BackwardRightWheelSensorOutHit.ImpactPoint,
		BackwardRightWheelSensorOutHit.ImpactNormal.Rotation(),
		70.f
	);
	//UE_LOG(LogTemp, Warning, TEXT("BackwardRightWheelSensorOutHit.ImpactNormal.X: %f"), BackwardRightWheelSensorOutHit.ImpactNormal.X);
	DrawDebugCoordinateSystem(
		GetWorld(), 
		BackwardLeftWheelSensorOutHit.ImpactPoint,
		BackwardLeftWheelSensorOutHit.ImpactNormal.Rotation(),
		70.f
	);
	//UE_LOG(LogTemp, Warning, TEXT("BackwardLeftWheelSensorOutHit.ImpactNormal.X: %f"), BackwardLeftWheelSensorOutHit.ImpactNormal.X);


	

	/*DrawDebugCoordinateSystem(
		GetWorld(),
		Normal,
		Normal.Rotation(),
		200.f
	);*/
	
	//UE_LOG(LogTemp, Warning, TEXT("HitActor: "));
	

	
}

FHitResult AFriendlyBaseTank::GetTracingResultByVisibility(FVector &StartLocation, float &DepthTracingValue)
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

void AFriendlyBaseTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	SetupTankOnGround();
}

void AFriendlyBaseTank::BeginPlay()
{
	Super::BeginPlay();

}

void AFriendlyBaseTank::SetTankPositionByTerrain()
{
	FHitResult OutHit;
	FVector Start = TankPivot->GetComponentLocation();
	FVector DeltaLength = FVector::ZeroVector;
	DeltaLength.Z = -100;
	FVector End = Start + DeltaLength;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	//DrawDebugLine(GetWorld(), Start, End, FColor::Red);

	GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECollisionChannel::ECC_Visibility, Params);

	//UE_LOG(LogTemp, Warning, TEXT("HitActor: "));
	FVector HitPoint = OutHit.ImpactPoint;
	FVector HItPointForwardVector = HitPoint.ForwardVector;
	FVector HitNormal = OutHit.ImpactNormal;
	FRotator HitRotator = HitNormal.Rotation();

	DrawDebugCoordinateSystem(GetWorld(), HitPoint, HitRotator, 100.f);
	//FVector DeltaLocationOffset = GetActorLocation();

	//FVector TankPivotLocation = TankPivot->GetComponentLocation();
	//DeltaLocationOffset.Z = DeltaLocationOffset.Z + (TankPivotLocation.Z - HitPoint.Z);

	//AddActorLocalOffset(DeltaLocationOffset, true);
	
	
	
}

