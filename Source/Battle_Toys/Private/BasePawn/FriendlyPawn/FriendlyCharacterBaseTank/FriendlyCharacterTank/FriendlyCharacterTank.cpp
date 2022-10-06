// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn/FriendlyPawn/FriendlyCharacterBaseTank/FriendlyCharacterTank/FriendlyCharacterTank.h"
#include "Kismet/GameplayStatics.h"
#include "BasePawn/EnemyPawn/EnemyPawn.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/PlayerTank/PlayerTank.h"

void AFriendlyCharacterTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FindClosestTarget();
}

AActor* AFriendlyCharacterTank::FindClosestTarget()
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

AActor* AFriendlyCharacterTank::FindClosestPlayer()
{
	TArray<AActor*> FoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerTank::StaticClass(), FoundActors);
	TArray<AActor*> ActorsInSearchRange;

	float CurrentMinDistance = SearchPlayerRadius;
	AActor* CurrentTargetActor = nullptr;


	if (FoundActors.IsEmpty())
	{
		return nullptr;
	}
	if (!FoundActors.IsEmpty())
	{
		for (int32 i = 0; i < FoundActors.Num(); i++)
		{
			float distance = FVector::Dist(GetActorLocation(), FoundActors[i]->GetActorLocation());

			if (distance < SearchPlayerRadius)
			{

				if (distance < CurrentMinDistance)
				{
					CurrentMinDistance = distance;
					CurrentTargetActor = FoundActors[i];
				}
			}

		}
	}
	if (CurrentTargetActor)
	{
		PlayerTankTarget = CurrentTargetActor;
		//UE_LOG(LogTemp, Warning, TEXT("FindedClosestPlayer!!"));

		return CurrentTargetActor;
	}
	/*FVector TargetToTurn = GetActorLocation() + GetActorForwardVector();
	TurnTankTowerToEnemy(TargetToTurn);*/
	PlayerTankTarget = nullptr;
	return nullptr;
}

bool AFriendlyCharacterTank::bStartFire()
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

bool AFriendlyCharacterTank::IsReadyForFire()
{
	return ShoodFire;
}

void AFriendlyCharacterTank::BeginPlay()
{
	Super::BeginPlay();
}
