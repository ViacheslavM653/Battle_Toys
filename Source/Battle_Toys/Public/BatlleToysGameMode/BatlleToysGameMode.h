// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "BatlleToysGameMode.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API ABatlleToysGameMode : public AGameModeBase
{
	GENERATED_BODY()
	
public:

	void ActorDied(AActor* DeadActor);
};
