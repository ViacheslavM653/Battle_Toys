// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeServices/BTS_ETow_TargetLocationIfSeen.h"
#include "GameFramework\Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BasePawn/EnemyPawn/BaseEnemyTower/EnemyTower/EnemyTower.h"
#include "Kismet/GameplayStatics.h"

UBTS_ETow_TargetLocationIfSeen::UBTS_ETow_TargetLocationIfSeen()
{
	NodeName = TEXT("ETow Update Target Location If Seen");
}

void UBTS_ETow_TargetLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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
        AActor* TargetActor = Cast<AEnemyTower>(OwnerPawn)->FindClosestTarget();
        if (TargetActor)
        {
            if (OwnerComp.GetAIOwner()->LineOfSightTo(TargetActor))
            {
                OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), TargetActor);
            }
            else
            {
                OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
            }
        }

    }
}
