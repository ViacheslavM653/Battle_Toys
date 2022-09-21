// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeServices/BTS_SetStartFireCondition.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTS_SetStartFireCondition::UBTS_SetStartFireCondition()
{
	NodeName = TEXT("Set Start FireCondition");
}

void UBTS_SetStartFireCondition::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return;
	}

	OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), true);
}
