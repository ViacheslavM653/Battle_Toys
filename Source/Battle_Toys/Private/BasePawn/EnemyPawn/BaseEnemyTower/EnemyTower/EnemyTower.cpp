// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn/EnemyPawn/BaseEnemyTower/EnemyTower/EnemyTower.h"
#include "Kismet/GameplayStatics.h"
#include "BasePawn/FriendlyPawn/FriendlyPawn.h"

void AEnemyTower::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FindClosestTarget();
}

void AEnemyTower::BeginPlay()
{
	Super::BeginPlay();
}

AActor* AEnemyTower::FindClosestTarget()
{

	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFriendlyPawn::StaticClass(), FoundActors);
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
	FVector TargetToTurn = GetActorLocation() + GetActorForwardVector();
	TurnTankTowerToEnemy(TargetToTurn);
	TargetToShot = nullptr;
	return nullptr;
}

bool AEnemyTower::bStartFire()
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