// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn/FriendlyPawn/FriendlyBaseTower/FriendlyTower/FriendlyTower.h"
#include "Kismet/GameplayStatics.h"
#include "BasePawn/EnemyPawn/EnemyPawn.h"


void AFriendlyTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FindClosestTarget();
}

void AFriendlyTower::BeginPlay()
{
	Super::BeginPlay();
}

AActor* AFriendlyTower::FindClosestTarget()
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
	ShoodFire = false;
	return nullptr;
}

bool AFriendlyTower::bStartFire()
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

bool AFriendlyTower::IsReadyForFire()
{
	return ShoodFire;
}
