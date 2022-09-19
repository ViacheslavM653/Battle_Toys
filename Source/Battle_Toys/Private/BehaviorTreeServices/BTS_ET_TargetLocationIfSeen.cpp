// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeServices/BTS_ET_TargetLocationIfSeen.h"
#include "GameFramework\Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BasePawn/EnemyPawn/BaseEnemyTank/EnemyTank/EnemyTank.h"
#include "Kismet/GameplayStatics.h"

UBTS_ET_TargetLocationIfSeen::UBTS_ET_TargetLocationIfSeen()
{
	NodeName = TEXT("ET Update Target Location If Seen");
}

void UBTS_ET_TargetLocationIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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
