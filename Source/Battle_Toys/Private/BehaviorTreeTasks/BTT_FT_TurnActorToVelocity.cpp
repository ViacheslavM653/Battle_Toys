// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeTasks/BTT_FT_TurnActorToVelocity.h"
#include "BasePawn/FriendlyPawn/FriendlyCharacterBaseTank/FriendlyCharacterTank/FriendlyCharacterTank.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UBTT_FT_TurnActorToVelocity::UBTT_FT_TurnActorToVelocity()
{
	NodeName = TEXT("FT Turn Tank Acording to Velocity");
}

EBTNodeResult::Type UBTT_FT_TurnActorToVelocity::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	AFriendlyCharacterTank* OwnerFriendlyTank = Cast<AFriendlyCharacterTank>(OwnerComp.GetAIOwner()->GetPawn());
	if (OwnerFriendlyTank == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	OwnerFriendlyTank->TurnActorAccordingToVelocity();

	return EBTNodeResult::Succeeded;
}
