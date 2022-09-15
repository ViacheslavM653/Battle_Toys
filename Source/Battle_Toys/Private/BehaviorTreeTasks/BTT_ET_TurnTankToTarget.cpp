// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeTasks/BTT_ET_TurnTankToTarget.h"
#include "BasePawn/EnemyPawn/BaseEnemyTank/EnemyTank/EnemyTank.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UBTT_ET_TurnTankToTarget::UBTT_ET_TurnTankToTarget()
{
	NodeName = TEXT("ET Turn Tank To Target");
}

EBTNodeResult::Type UBTT_ET_TurnTankToTarget::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);
	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	AEnemyTank* OwnerEnemyTank = Cast<AEnemyTank>(OwnerComp.GetAIOwner()->GetPawn());
	if (OwnerEnemyTank == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	FVector TargetLocation = OwnerComp.GetBlackboardComponent()->GetValueAsVector(FName("LastKnownPlayerLocation"));

	OwnerEnemyTank->TurnActorToTarget(TargetLocation);

	return EBTNodeResult::Succeeded;
}
