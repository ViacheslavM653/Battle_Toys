// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyTank/HostageTank/HostageTank.h"
#include "Kismet/GameplayStatics.h"
#include "BasePawn/EnemyPawn/EnemyPawn.h"

void AHostageTank::BeginPlay()
{
	Super::BeginPlay();

	HostageFreeStatus = false;
}

int32 AHostageTank::GetHostageID()
{
	return HostageID;
}

void AHostageTank::SetFreeHostage()
{
	HostageFreeStatus = true;
}

bool AHostageTank::GetHostageFreeStatus()
{
	return HostageFreeStatus;
}

AActor* AHostageTank::FindClosestTarget()
{
	if (HostageFreeStatus)
	{
		TArray<AActor*> FoundActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyPawn::StaticClass(), FoundActors);
		TArray<AActor*> ActorsInSearchRange;

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

					if (distance < CurrentMinDistance)
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
			return CurrentTargetActorForShoot;
		}

	}
	FVector TargetToTurn = GetActorLocation() + GetActorForwardVector();
	TurnTankTowerToEnemy(TargetToTurn);
	TargetToShot = nullptr;
	return nullptr;
	
}

bool AHostageTank::bStartFire()
{
	if (HostageFreeStatus)
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

	}
	else
	{
		return false;
	}
	return false;
}
