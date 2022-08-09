// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "BattleToysProjectile/BattleToysProjectile.h"

AFriendlyBaseTank::AFriendlyBaseTank()
{
	//Creating Hirarchical Structure
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	RootComponent = CapsuleComponent;
	TankHullSkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Tank Hull SkeletalMesh"));
	TankHullSkeletalMesh->SetupAttachment(CapsuleComponent);
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
	MovementComponent = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Projectile Spawn Point"));
}

void AFriendlyBaseTank::Fire()
{
	FVector Location = ProjectileSpawnPoint->GetComponentLocation();
	FRotator Rotation = ProjectileSpawnPoint->GetComponentRotation();

	ABattleToysProjectile* Projectile = GetWorld()->SpawnActor<ABattleToysProjectile>(ABasePawn::ProjectileClass, Location, Rotation);
	Projectile->SetOwner(this);
}

