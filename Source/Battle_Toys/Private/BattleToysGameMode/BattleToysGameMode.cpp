// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleToysGameMode/BattleToysGameMode.h"
#include "EngineUtils.h"
#include "GameFramework/Controller.h"
#include "BatleTankPlayerController/BatleTankPlayerController.h"
#include "Kismet\GameplayStatics.h"
#include "BasePawn/EnemyPawn/EnemyPawn.h"
#include "BasePawn/EnemyPawn/BaseEnemyTank/EnemyTank/EnemyBossTank/EnemyBossTank.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyTank/HostageTank/HostageTank.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/PlayerTank/PlayerTank.h"
#include "BasePawn/BasePawn.h"


void ABattleToysGameMode::ActorDied(AActor* DeadActor)
{
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
	if (AEnemyBossTank* EnemyBossTank = Cast<AEnemyBossTank>(DeadActor))
	{
		int32 HoldHostageID = EnemyBossTank->GetHoldHostageID();
		TArray<AActor*> FoundAllAHostageTanks;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), AHostageTank::StaticClass(), FoundAllAHostageTanks);
		if (!FoundAllAHostageTanks.IsEmpty())
		{
			for (int32 i = 0; i < FoundAllAHostageTanks.Num(); i++)
			{
				int32 HostageID = Cast<AHostageTank>(FoundAllAHostageTanks[i])->GetHostageID();
				if (HoldHostageID == HostageID)
				{
					Cast<AHostageTank>(FoundAllAHostageTanks[i])->SetFreeHostage();
				}

			}
		}
		EnemyBossTank->HandleDestruction();
	}
	else if (ABasePawn* BasePawn = Cast<ABasePawn>(DeadActor))
	{
		BasePawn->HandleDestruction();
	}
	//Check IsAlive  all enemies
	TArray<AActor*> FoundAllEmenyes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyPawn::StaticClass(), FoundAllEmenyes);
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
