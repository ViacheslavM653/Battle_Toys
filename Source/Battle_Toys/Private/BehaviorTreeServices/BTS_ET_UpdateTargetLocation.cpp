// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeServices/BTS_ET_UpdateTargetLocation.h"
#include "GameFramework\Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BasePawn/EnemyPawn/BaseEnemyTank/EnemyTank/EnemyTank.h"

UBTS_ET_UpdateTargetLocation::UBTS_ET_UpdateTargetLocation()
{
	NodeName = TEXT("ET Update Target Location");
}

void UBTS_ET_UpdateTargetLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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
    if (Cast<AEnemyTank>(OwnerPawn))
    {
        AActor* TargetActor = Cast<AEnemyTank>(OwnerPawn)->FindClosestTarget();
        if (TargetActor)
        {
            OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), TargetActor->GetActorLocation());
        }
        
       
    }
}
