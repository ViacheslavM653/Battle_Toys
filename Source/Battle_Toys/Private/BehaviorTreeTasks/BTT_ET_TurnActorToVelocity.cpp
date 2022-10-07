// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeTasks/BTT_ET_TurnActorToVelocity.h"
#include "BasePawn/EnemyPawn/EnemyCharacterBaseTank/EnemyCharacterTank/EnemyCharacterTank.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UBTT_ET_TurnActorToVelocity::UBTT_ET_TurnActorToVelocity()
{
	NodeName = TEXT("ET Turn Tank Acording to Velocity");
}

EBTNodeResult::Type UBTT_ET_TurnActorToVelocity::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	AEnemyCharacterTank* OwnerEnemyTank = Cast<AEnemyCharacterTank>(OwnerComp.GetAIOwner()->GetPawn());
	if (OwnerEnemyTank == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	
	OwnerEnemyTank->TurnActorAccordingToVelocity();

	return EBTNodeResult::Succeeded;
}
