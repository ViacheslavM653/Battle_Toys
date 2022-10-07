// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeTasks/BTT_ET_Shoot.h"
#include "BasePawn/EnemyPawn/EnemyCharacterBaseTank/EnemyCharacterTank/EnemyCharacterTank.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UBTT_ET_Shoot::UBTT_ET_Shoot()
{
	NodeName = TEXT("Enemy Tank Shoot");
}

EBTNodeResult::Type UBTT_ET_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
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
	
	OwnerEnemyTank->Fire();

	return EBTNodeResult::Succeeded;

	
}
