// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTS_FT_GetFireStatus.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API UBTS_FT_GetFireStatus : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTS_FT_GetFireStatus();

protected:

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
