// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn/FriendlyPawn/FriendlyBaseTank/PlayerTank/PlayerTank.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "HealthComponent/HealthComponent.h"
#include "BattleToysProjectile/BattleToysProjectile.h"
#include "TimerManager.h"
#include "Kismet/GameplayStatics.h"

void APlayerTank::BeginPlay()
{
	Super::BeginPlay();

	PlayerTankController = Cast<APlayerController>(GetController());
}

void APlayerTank::Fire()
{
	ActuallyFire(FireStatus);
	if (FireStatus)
	{
		FireStatus = false;
		GetWorldTimerManager().SetTimer(FireTimerHandle, this, &APlayerTank::SetFirePermission, ShotInverval);
		float TimeRemaning = FMath::RoundToInt(ShotInverval / GetWorld()->GetDeltaSeconds());
		ReloadSubtractionDelta = 1 / TimeRemaning;
		ReloadRateStatus = 0.f;
			
	}
	
	

}

float APlayerTank::ReloadRate()
{
	
	if (FireStatus)
	{
		ReloadRateStatus = 0.0f;
	}
	if (!FireStatus)
	{
		if (ReloadRateStatus >= 0)
		{
			ReloadRateStatus += ReloadSubtractionDelta;
		}
		if (ReloadRateStatus > 1)
		{
			ReloadRateStatus = 1.0f;
		}
		
	}
	else
	{
		ReloadRateStatus = 0.0f;
	}
	
	return ReloadRateStatus;
		
}

void APlayerTank::HandleDestruction()
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
	//Destroy();
}

void APlayerTank::ActuallyFire(bool FirePermission)
{
	if (FirePermission)
	{
		FVector Location = ProjectileSpawnPoint->GetComponentLocation();
		FRotator Rotation = ProjectileSpawnPoint->GetComponentRotation();
		if (ProjectileClass)
		{
			ABattleToysProjectile* Projectile = GetWorld()->SpawnActor<ABattleToysProjectile>(ABasePawn::ProjectileClass, Location, Rotation);
			Projectile->SetOwner(this);
		}
	}
	
}


void APlayerTank::SetFirePermission()
{
	FireStatus = true;
}

void APlayerTank::TankTowerControl()
{
	if (PlayerTankController)
	{
		FHitResult HitResult;
		PlayerTankController->GetHitResultUnderCursor(
			ECollisionChannel::ECC_Visibility,
			false,
			HitResult
		);
		this->TurnTankTowerToEnemy(HitResult.ImpactPoint);
	}
}

void APlayerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	TankTowerControl();
		
	if (IsGoodMod)
	{
		SetHealthUpgrade(100.f);
	}
}

void APlayerTank::SetSpeedUpgrade(float Multiplier)
{
	if (MovementComponent && Multiplier > 0)
	{
		MovementComponent->MaxSpeed = MovementComponent->MaxSpeed * Multiplier;
		MovementComponent->Acceleration = MovementComponent->Acceleration * Multiplier;
		MovementComponent->Deceleration = MovementComponent->Deceleration * Multiplier;
	}
}

void APlayerTank::SetHealthUpgrade(float AddValue)
{
	if (AddValue > 0)
	{
		HealthComponent->AddHealthFromUpgrade(AddValue);
	}
}

APlayerController* APlayerTank::GetPlayerTankController() const
{
	return PlayerTankController;
}

