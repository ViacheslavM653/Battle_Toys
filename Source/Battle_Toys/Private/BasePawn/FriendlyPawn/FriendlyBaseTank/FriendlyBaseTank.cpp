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
	FHitResult OutHit;
	FVector Start = TankPivot->GetComponentLocation();
	FVector DeltaLength = FVector::ZeroVector;
	DeltaLength.Z = -100;
	FVector End = Start + DeltaLength;
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECollisionChannel::ECC_Visibility, Params);


	//Find Ground Point
	FVector HitPoint = OutHit.ImpactPoint;
	//Prepare Vector for Move
	FVector MovementInputVector = GetActorForwardVector();
	FVector TankPivotLocation = TankPivot->GetComponentLocation();
	float Atan = atan2f(FVector::Distance(TankPivotLocation, HitPoint), 1.f);
	//1.5708 rad in 90 degeece

	if (AxisValue > 0)
	{
		MovementInputVector.Z = MovementInputVector.Z - (Atan / 1.5708);
	}
	if (AxisValue < 0)
	{
		MovementInputVector.Z = MovementInputVector.Z + (Atan / 1.5708);
	}

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

void AFriendlyBaseTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	
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

