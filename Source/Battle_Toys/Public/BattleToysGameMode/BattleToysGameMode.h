// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BattleToysGameMode.generated.h"


/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API ABattleToysGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	virtual void ActorDied(AActor* DeadActor);

private:

	class ABatleTankPlayerController* BatleTankPlayerController;

	void EndGame(bool bIsPlayerWinner);

};
