// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTS_ET_TargetLocationIfSeen.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API UBTS_ET_TargetLocationIfSeen : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTS_ET_TargetLocationIfSeen();

protected:

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
