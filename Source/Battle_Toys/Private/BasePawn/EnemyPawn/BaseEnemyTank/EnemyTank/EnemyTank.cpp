// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn/EnemyPawn/BaseEnemyTank/EnemyTank/EnemyTank.h"
#include "Kismet/GameplayStatics.h"
#include "BasePawn/FriendlyPawn/FriendlyPawn.h"
#include "Kismet/GameplayStatics.h"
#include "BaseUpgradePlayerTank/BaseUpgradePlayerTank.h"
#include "BasePawn/BasePawn.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyTank/HostageTank/HostageTank.h"

void AEnemyTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FindClosestTarget();
}

void AEnemyTank::BeginPlay()
{
	Super::BeginPlay();
}

AActor* AEnemyTank::FindClosestTarget()
{

	TArray<AActor*> AllFoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFriendlyPawn::StaticClass(), AllFoundActors);
	

	TArray<AActor*> FoundActors;
	for (int32 i = 0; i < AllFoundActors.Num(); i++)
	{
		if (!Cast<AHostageTank>(AllFoundActors[i]))
		{
			FoundActors.Add(AllFoundActors[i]);
		}
		if (Cast<AHostageTank>(AllFoundActors[i]))
		{
			if (Cast<AHostageTank>(AllFoundActors[i])->GetHostageFreeStatus())
			{
				FoundActors.Add(AllFoundActors[i]);
			}
		}
	}
	float CurrentMinDistance = SearchTargetRadius;
	AActor* CurrentTargetActorForShoot = nullptr;


	if (FoundActors.IsEmpty())
	{
		return nullptr;
	}
	if (!FoundActors.IsEmpty())
	{
		for (int32 i = 0; i < FoundActors.Num(); i++)
		{
			float distance = FVector::Dist(GetActorLocation(), FoundActors[i]->GetActorLocation());

			if (distance < SearchTargetRadius)
			{
				
				if (distance < CurrentMinDistance )
				{
					CurrentMinDistance = distance;
					CurrentTargetActorForShoot = FoundActors[i];
				}
			}

		}
	}
	if (CurrentTargetActorForShoot)
	{
		TargetToShot = CurrentTargetActorForShoot;
		FVector TargetToTurn = CurrentTargetActorForShoot->GetActorLocation();
		

		TurnTankTowerToEnemy(TargetToTurn);

		float distance = FVector::Dist(GetActorLocation(), CurrentTargetActorForShoot->GetActorLocation());
		if (Cast<ABasePawn>(CurrentTargetActorForShoot)->IsPawnAlive())
		{
			if (distance < FireRange)
			{
				ShoodFire = true;
			}
			if (distance > FireRange)
			{
				ShoodFire = false;
			}
			if (Cast<AHostageTank>(CurrentTargetActorForShoot))
			{
				if (!Cast<AHostageTank>(CurrentTargetActorForShoot)->GetHostageFreeStatus())
				{
					ShoodFire = false;

				}
			}

		}
		if (!Cast<ABasePawn>(CurrentTargetActorForShoot)->IsPawnAlive()) 
		{
			ShoodFire = false;
			
		}

		return CurrentTargetActorForShoot;
	}
	FVector TargetToTurn = GetActorLocation() + GetActorForwardVector();
	TurnTankTowerToEnemy(TargetToTurn);
	TargetToShot = nullptr;
	return nullptr;
}

bool AEnemyTank::bStartFire()
{
	if (TargetToShot)
	{
		float distance = FVector::Dist(GetActorLocation(), TargetToShot->GetActorLocation());
		if (distance < FireRange)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	else
	{
		return false;
	}
}

void AEnemyTank::HandleDestruction()
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
	FVector Location = GetActorLocation();
	FRotator Rotation = GetActorRotation();
	SetPawnDie();
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	Destroy();
	if (UpgradePlayerTankClass)
	{
		ABaseUpgradePlayerTank* UpgradeActor =  
			GetWorld()->SpawnActor<ABaseUpgradePlayerTank>(AEnemyTank::UpgradePlayerTankClass, Location, Rotation);
	}
}

bool AEnemyTank::IsReadyForFire()
{
	return ShoodFire;
}
