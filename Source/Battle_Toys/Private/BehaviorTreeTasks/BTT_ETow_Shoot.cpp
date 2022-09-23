// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeTasks/BTT_ETow_Shoot.h"
#include "BasePawn/EnemyPawn/BaseEnemyTower/EnemyTower/EnemyTower.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UBTT_ETow_Shoot::UBTT_ETow_Shoot()
{
	NodeName = TEXT("Enemy Tower Shoot");
}

EBTNodeResult::Type UBTT_ETow_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	AEnemyTower* OwnerEnemyTower = Cast<AEnemyTower>(OwnerComp.GetAIOwner()->GetPawn());
	if (OwnerEnemyTower == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	OwnerEnemyTower->Fire();

	return EBTNodeResult::Succeeded;
}
