// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn/FriendlyPawn/FriendlyBaseTower/FriendlyTower/FriendlyTower.h"
#include "Kismet/GameplayStatics.h"
#include "BasePawn/EnemyPawn/EnemyPawn.h"
#include "BasePawn/EnemyPawn/EnemyCharacterBaseTank/EnemyCharacterTank/EnemyCharacterTank.h"


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

	TArray<AActor*> AllFoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyCharacterTank::StaticClass(), AllFoundActors);
	TArray<AActor*> AllFoundPawns;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyPawn::StaticClass(), AllFoundPawns);
	if (AllFoundPawns.Num() > 0)
	{
		for (int32 i = 0; i < AllFoundPawns.Num(); i++)
		{
			AllFoundActors.Add(AllFoundPawns[i]);
		}
	}

	float CurrentMinDistance = SearchTargetRadius;
	AActor* CurrentTargetActorForShoot = nullptr;


	if (AllFoundActors.IsEmpty())
	{
		return nullptr;
	}
	if (!AllFoundActors.IsEmpty())
	{
		for (int32 i = 0; i < AllFoundActors.Num(); i++)
		{
			float distance = FVector::Dist(GetActorLocation(), AllFoundActors[i]->GetActorLocation());

			if (distance < SearchTargetRadius)
			{

				if (distance < CurrentMinDistance)
				{
					CurrentMinDistance = distance;
					CurrentTargetActorForShoot = AllFoundActors[i];
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
		if (Cast<ABasePawn>(CurrentTargetActorForShoot))
		{
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
		}
		if (Cast<AEnemyCharacterTank>(CurrentTargetActorForShoot))
		{
			if (Cast<AEnemyCharacterTank>(CurrentTargetActorForShoot)->IsPawnAlive())
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
			if (!Cast<AEnemyCharacterTank>(CurrentTargetActorForShoot)->IsPawnAlive())
			{
				ShoodFire = false;
			}

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
