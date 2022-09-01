// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn/EnemyPawn/BaseEnemyTower/BaseEnemyTower.h"
#include "Components/CapsuleComponent.h"
#include "BattleToysProjectile/BattleToysProjectile.h"
#include "Kismet/GameplayStatics.h"

ABaseEnemyTower::ABaseEnemyTower()
{
	//Creating Hirarchical Structure
	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	CapsuleComponent->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	RootComponent = CapsuleComponent;

	TowerHullMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tower Hull Mesh"));
	TowerHullMesh->SetupAttachment(CapsuleComponent);

	TowerTowerMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tower Tower Mesh"));
	TowerTowerMesh->SetupAttachment(TowerHullMesh);

	TowerBarrelMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Tower Barrel Mesh"));
	TowerBarrelMesh->SetupAttachment(TowerTowerMesh);

	ProjectileSpawnPoint = CreateDefaultSubobject<USceneComponent>(TEXT("Projectile Spawn Point"));
	ProjectileSpawnPoint->SetupAttachment(TowerBarrelMesh);
}

void ABaseEnemyTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ABaseEnemyTower::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseEnemyTower::Fire()
{
	FVector Location = ProjectileSpawnPoint->GetComponentLocation();
	FRotator Rotation = ProjectileSpawnPoint->GetComponentRotation();
	if (ProjectileClass)
	{
		ABattleToysProjectile* Projectile = GetWorld()->SpawnActor<ABattleToysProjectile>(ABasePawn::ProjectileClass, Location, Rotation);
		Projectile->SetOwner(this);
	}

}

void ABaseEnemyTower::TurnTankTowerToEnemy(FVector& LookAtTarget)
{
	FVector ToTarget = LookAtTarget - TowerHullMesh->GetComponentLocation();
	FVector ToTargetProjectedXY = FVector::VectorPlaneProject(ToTarget, FVector(0, 0, 1));
	FRotator TargetRotator = FRotator(0.f, ToTargetProjectedXY.Rotation().Yaw, 0.f);
	TargetRotator = FMath::RInterpTo(
		TowerTowerMesh->GetComponentRotation(),
		TargetRotator,
		UGameplayStatics::GetWorldDeltaSeconds(this),
		TurnTowerTowerInterpolationSpeed
	);

	TowerTowerMesh->SetWorldRotation(TargetRotator);
}
