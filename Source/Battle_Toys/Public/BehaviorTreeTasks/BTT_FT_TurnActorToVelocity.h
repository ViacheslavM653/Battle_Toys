// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_FT_TurnActorToVelocity.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API UBTT_FT_TurnActorToVelocity : public UBTTaskNode
{
	GENERATED_BODY()
public:
	UBTT_FT_TurnActorToVelocity();

protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
