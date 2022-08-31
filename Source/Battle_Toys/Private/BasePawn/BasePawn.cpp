// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn/BasePawn.h"
#include "Kismet/GameplayStatics.h"
#include "HealthComponent/HealthComponent.h"
#include "BattleToysProjectile/BattleToysProjectile.h"

// Sets default values
ABasePawn::ABasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));

}

void ABasePawn::AddHealthFromUpgrade(float HealingValue)
{
	if (HealingValue && HealingValue >= 0)
	{
		HealthComponent->AddHealthFromUpgrade(HealingValue);
	}
	UE_LOG(LogTemp, Warning, TEXT("Health changed! HealthComponent: %f"), HealthComponent);
}

float ABasePawn::GetProjectileDamage()
{
	return ProjectileDamage;
}

float ABasePawn::GetProjectileSpeed()
{
	return ProjectileSpeed;
}

void ABasePawn::SetUpgradeForProjectileDamage(float UpgradeProjectileDamageMultiplier)
{
	if (UpgradeProjectileDamageMultiplier && UpgradeProjectileDamageMultiplier > 0.f)
	{
		ProjectileDamage *= UpgradeProjectileDamageMultiplier;
	}
	UE_LOG(LogTemp, Warning, TEXT("ProjectileDamage changed! ProjectileDamage: %f"), ProjectileDamage);
}

void ABasePawn::SetUpgradeForProjectileSpeed(float UpgradeProjectileSpeedMultiplier)
{
	if (UpgradeProjectileSpeedMultiplier && UpgradeProjectileSpeedMultiplier > 0)
	{
		ProjectileSpeed *= UpgradeProjectileSpeedMultiplier;
	}
}


// Called when the game starts or when spawned
void ABasePawn::BeginPlay()
{
	Super::BeginPlay();
	bPawnAlive = true;
}


// Called every frame
void ABasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABasePawn::HandleDestruction()
{
	if (DeathParticles)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticles, GetActorLocation(), GetActorRotation());
	}
	if (DeathSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
	}
	if (DeathCameraShakeClass)
	{
		GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(DeathCameraShakeClass);
	}
	SetPawnDie();
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	Destroy();
}

void ABasePawn::SetPawnDie()
{
	bPawnAlive = false;
}

bool ABasePawn::IsPawnAlive()
{
	return bPawnAlive;
}

