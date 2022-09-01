// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn/EnemyPawn/BaseEnemyTank/EnemyTank/EnemyTank.h"
#include "EnemyBossTank.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API AEnemyBossTank : public AEnemyTank
{
	GENERATED_BODY()

public:	

	int32 GetHoldHostageID();

private:
	UPROPERTY(EditAnywhere, Category = "HoldHostageID")
	int32 HoldHostageID = 0;
};
