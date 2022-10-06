// Fill out your copyright notice in the Description page of Project Settings.


#include "BasePawn/EnemyPawn/EnemyCharacterBaseTank/EnemyCharacterTank/EnemyCharacterTank.h"
#include "Kismet/GameplayStatics.h"
#include "BasePawn/FriendlyPawn/FriendlyCharacterBaseTank/FriendlyCharacterBaseTank.h"
#include "BasePawn/FriendlyPawn/FriendlyPawn.h"
#include "Kismet/GameplayStatics.h"
#include "BaseUpgradePlayerTank/BaseUpgradePlayerTank.h"
#include "BasePawn/BasePawn.h"
#include "BasePawn/FriendlyPawn/FriendlyCharacterBaseTank/FriendlyCharacterTank/FriendlyHostageCharacterTank/FriendlyHostageCharacterTank.h"

void AEnemyCharacterTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FindClosestTarget();
}

AActor* AEnemyCharacterTank::FindClosestTarget()
{
	TArray<AActor*> AllFoundActors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFriendlyCharacterTank::StaticClass(), AllFoundActors);
	TArray<AActor*> AllFoundPawns;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFriendlyPawn::StaticClass(), AllFoundPawns);
	if (AllFoundPawns.Num() > 0)
	{
		for (int32 i = 0; i < AllFoundPawns.Num(); i++)
		{
			AllFoundActors.Add(AllFoundPawns[i]);
		}
	}
	

	TArray<AActor*> FoundActors;
	for (int32 i = 0; i < AllFoundActors.Num(); i++)
	{
		if (!Cast<AFriendlyHostageCharacterTank>(AllFoundActors[i]))
		{
			FoundActors.Add(AllFoundActors[i]);
		}
		if (Cast<AFriendlyHostageCharacterTank>(AllFoundActors[i]))
		{
			if (Cast<AFriendlyHostageCharacterTank>(AllFoundActors[i])->GetHostageFreeStatus())
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
		UE_LOG(LogTemp, Warning, TEXT("TargetToShot: %s"), *TargetToShot->GetActorNameOrLabel())

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
		if (Cast<AFriendlyCharacterTank>(CurrentTargetActorForShoot))
		{
			if (Cast<AFriendlyCharacterTank>(CurrentTargetActorForShoot)->IsPawnAlive())
			{
				if (distance < FireRange)
				{
					ShoodFire = true;
				}
				if (distance > FireRange)
				{
					ShoodFire = false;
				}

				if (Cast<AFriendlyHostageCharacterTank>(CurrentTargetActorForShoot))
				{
					if (!Cast<AFriendlyHostageCharacterTank>(CurrentTargetActorForShoot)->GetHostageFreeStatus())
					{
						ShoodFire = false;

					}
				}
			}
			if (!Cast<AFriendlyCharacterTank>(CurrentTargetActorForShoot)->IsPawnAlive())
			{
				ShoodFire = false;
			}

		}

		return CurrentTargetActorForShoot;
	}
	FVector TargetToTurn = GetActorLocation() + GetActorForwardVector();
	TurnTankTowerToEnemy(TargetToTurn);
	TargetToShot = nullptr;
	return nullptr;
}

bool AEnemyCharacterTank::bStartFire()
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

void AEnemyCharacterTank::HandleDestruction()
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
			GetWorld()->SpawnActor<ABaseUpgradePlayerTank>(AEnemyCharacterTank::UpgradePlayerTankClass, Location, Rotation);
	}
}

bool AEnemyCharacterTank::IsReadyForFire()
{
	return ShoodFire;
}

void AEnemyCharacterTank::BeginPlay()
{
	Super::BeginPlay();
}
