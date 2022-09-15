// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTT_ET_Shoot.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API UBTT_ET_Shoot : public UBTTaskNode
{
	GENERATED_BODY()
	
public:

	UBTT_ET_Shoot();

protected:

	virtual EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
};
