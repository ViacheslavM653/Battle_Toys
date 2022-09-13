// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BatleTankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API ABatleTankPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
	
};
