// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeServices/BTS_ET_GetTankTurnTime.h"
#include "GameFramework\Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BasePawn/EnemyPawn/BaseEnemyTank/EnemyTank/EnemyTank.h"

UBTS_ET_GetTankTurnTime::UBTS_ET_GetTankTurnTime()
{
	NodeName = TEXT("ET Get Tank Turn Time");
}

void UBTS_ET_GetTankTurnTime::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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
        float TurnTankInterpolationSpeed = Cast<AEnemyTank>(OwnerPawn)->GetTurnTankInterpolationSpeed();
        if (TurnTankInterpolationSpeed)
        {
            OwnerComp.GetBlackboardComponent()->SetValueAsFloat(GetSelectedBlackboardKey(), TurnTankInterpolationSpeed);
        }


    }
}
