// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeTasks/BTT_FT_Shoot.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyTank/FriendlyTank.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"

UBTT_FT_Shoot::UBTT_FT_Shoot()
{
	NodeName = TEXT("Friendly Tank Shoot");
}

EBTNodeResult::Type UBTT_FT_Shoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr)
	{
		return EBTNodeResult::Failed;
	}
	AFriendlyTank* OwnerTank = Cast<AFriendlyTank>(OwnerComp.GetAIOwner()->GetPawn());
	if (OwnerTank == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	OwnerTank->Fire();

	return EBTNodeResult::Succeeded;
}
