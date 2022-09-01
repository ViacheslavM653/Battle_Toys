// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn/FriendlyPawn/FriendlyBaseTank/PlayerTank/PlayerTank.h"
#include "GameFramework/FloatingPawnMovement.h"
#include "HealthComponent/HealthComponent.h"

void APlayerTank::BeginPlay()
{
	Super::BeginPlay();

	PlayerTankController = Cast<APlayerController>(GetController());
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
