// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeServices/BTS_FTow_GetFireStatus.h"
#include "GameFramework\Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTower/FriendlyTower/FriendlyTower.h"

UBTS_FTow_GetFireStatus::UBTS_FTow_GetFireStatus()
{
	NodeName = TEXT("Get FTower Fire Status");
}

void UBTS_FTow_GetFireStatus::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    if (OwnerComp.GetAIOwner() == nullptr)
    {
        return;
    }
    APawn* OwnerPawn = OwnerComp.GetAIOwner()->GetPawn();
    if (OwnerPawn == nullptr)
    {
        return;
    }
    if (Cast<AFriendlyTower>(OwnerPawn))
    {
        bool FireStatus = Cast<AFriendlyTower>(OwnerPawn)->IsReadyForFire();

        OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), FireStatus);
    }
}
