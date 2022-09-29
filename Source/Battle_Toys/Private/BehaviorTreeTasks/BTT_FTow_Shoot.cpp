// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeTasks/BTT_FTow_Shoot.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTower/FriendlyTower/FriendlyTower.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UBTT_FTow_Shoot::UBTT_FTow_Shoot()
{
	NodeName = TEXT("Friendly Tower Shoot");
}

EBTNodeResult::Type UBTT_FTow_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	AFriendlyTower* OwnerTower = Cast<AFriendlyTower>(OwnerComp.GetAIOwner()->GetPawn());
	if (OwnerTower == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	OwnerTower->Fire();

	return EBTNodeResult::Succeeded;
}
