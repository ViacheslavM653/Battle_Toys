// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeServices/BTS_ETow_GetFireStatus.h"
#include "GameFramework\Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BasePawn/EnemyPawn/BaseEnemyTower/EnemyTower/EnemyTower.h"

UBTS_ETow_GetFireStatus::UBTS_ETow_GetFireStatus()
{
	NodeName = TEXT("Get ETower Fire Status");
}

void UBTS_ETow_GetFireStatus::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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
    if (Cast<AEnemyTower>(OwnerPawn))
    {
        
        if (Cast<AEnemyTower>(OwnerPawn)->FindClosestTarget())
        {
            if (OwnerComp.GetAIOwner()->LineOfSightTo(Cast<AEnemyTower>(OwnerPawn)->FindClosestTarget()))
            {
                bool FireStatus = Cast<AEnemyTower>(OwnerPawn)->IsReadyForFire();

                OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), FireStatus);

            }
        }
        else
        {
            OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), false);
        }
    }
}
