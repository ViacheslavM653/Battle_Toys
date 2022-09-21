// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTS_SetStartFireCondition.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API UBTS_SetStartFireCondition : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTS_SetStartFireCondition();

protected:

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

};
