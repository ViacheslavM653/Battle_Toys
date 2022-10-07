// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleToysGameMode/BattleToysGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "BatleTankPlayerController/BatleTankPlayerController.h"
#include "Kismet\GameplayStatics.h"
#include "BasePawn/EnemyPawn/EnemyPawn.h"
#include "BasePawn/EnemyPawn/BaseEnemyTank/EnemyTank/EnemyBossTank/EnemyBossTank.h"
#include "BasePawn/FriendlyPawn/FriendlyCharacterBaseTank/FriendlyCharacterTank/FriendlyHostageCharacterTank/FriendlyHostageCharacterTank.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/PlayerTank/PlayerTank.h"
#include "BasePawn/BasePawn.h"
#include "BaseDestructibleActor/BaseDestructibleActor.h"
#include "BasePawn/FriendlyPawn/FriendlyCharacterBaseTank/FriendlyCharacterBaseTank.h"
#include "BasePawn/EnemyPawn/EnemyCharacterBaseTank/EnemyCharacterTank/EnemyCharacterTank.h"
#include "BasePawn/EnemyPawn/EnemyCharacterBaseTank/EnemyCharacterTank/EnemyBossCharacterTank/EnemyBossCharacterTank.h"


void ABattleToysGameMode::ActorDied(AActor* DeadActor)
{
	//Check DeadActor is DestructibleActor
	if (ABaseDestructibleActor* DestructibleActor = Cast<ABaseDestructibleActor>(DeadActor))
	{
		Cast<ABaseDestructibleActor>(DeadActor)->HandleDestruction();
	}
	
	//Check DeadActor is player
	if (APlayerTank* PlayerTank  = Cast<APlayerTank>(DeadActor))
	{
		EndGame(false);
		PlayerTank->HandleDestruction();
		/*if (BatleTankPlayerController = Cast<ABatleTankPlayerController>(DeadActor->GetInstigatorController()))
		{
			BatleTankPlayerController->GetPawn()->EnableInput(false);
		}*/
	}
	//chek DeadActor is Boss
	if (AEnemyBossCharacterTank* EnemyBossTank = Cast<AEnemyBossCharacterTank>(DeadActor))
	{
		int32 HoldHostageID = EnemyBossTank->GetHoldHostageID();
		TArray<AActor*> FoundAllAHostageTanks;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AFriendlyHostageCharacterTank::StaticClass(), FoundAllAHostageTanks);
		if (!FoundAllAHostageTanks.IsEmpty())
		{
			for (int32 i = 0; i < FoundAllAHostageTanks.Num(); i++)
			{
				int32 HostageID = Cast<AFriendlyHostageCharacterTank>(FoundAllAHostageTanks[i])->GetHostageID();
				if (HoldHostageID == HostageID)
				{
					Cast<AFriendlyHostageCharacterTank>(FoundAllAHostageTanks[i])->SetFreeHostage();
				}

			}
		}
		EnemyBossTank->HandleDestruction();
	}
	if (AFriendlyCharacterBaseTank* FriendlyCharacterBaseTank = Cast<AFriendlyCharacterBaseTank>(DeadActor))
	{
		FriendlyCharacterBaseTank->HandleDestruction();
	}
	if (AEnemyCharacterTank* EnemyCharacterTank = Cast<AEnemyCharacterTank>(DeadActor))
	{
		EnemyCharacterTank->HandleDestruction();
	}
	else if (ABasePawn* BasePawn = Cast<ABasePawn>(DeadActor))
	{
		BasePawn->HandleDestruction();
	}


	//Check IsAlive  all enemies
	TArray<AActor*> FoundAllEmenyes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyPawn::StaticClass(), FoundAllEmenyes);
	TArray<AActor*> AllFoundCharacterTank;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyCharacterTank::StaticClass(), AllFoundCharacterTank);
	if (AllFoundCharacterTank.Num() > 0)
	{
		for (int32 i = 0; i < AllFoundCharacterTank.Num(); i++)
		{
			FoundAllEmenyes.Add(AllFoundCharacterTank[i]);
		}
	}

	if (!FoundAllEmenyes.Num())
	{
		EndGame(true);
	}
	
}

void ABattleToysGameMode::EndGame(bool bIsPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool bIsWinner = Controller->IsPlayerController() == bIsPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), bIsWinner);

	}
}
