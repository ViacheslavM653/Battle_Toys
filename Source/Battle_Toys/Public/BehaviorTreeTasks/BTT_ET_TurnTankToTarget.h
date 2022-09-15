// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_ET_TurnTankToTarget.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API UBTT_ET_TurnTankToTarget : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTT_ET_TurnTankToTarget();

protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
