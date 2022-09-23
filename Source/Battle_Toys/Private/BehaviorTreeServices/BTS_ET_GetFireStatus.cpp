// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeServices/BTS_ET_GetFireStatus.h"
#include "GameFramework\Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BasePawn/EnemyPawn/BaseEnemyTank/EnemyTank/EnemyTank.h"



UBTS_ET_GetFireStatus::UBTS_ET_GetFireStatus()
{
	NodeName = TEXT("Get ETower Fire Status");
}

void UBTS_ET_GetFireStatus::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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
        bool FireStatus = Cast<AEnemyTank>(OwnerPawn)->IsReadyForFire();
        
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), FireStatus);

    }


}


