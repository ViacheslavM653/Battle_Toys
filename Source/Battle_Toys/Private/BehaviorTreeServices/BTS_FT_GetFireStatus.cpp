// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeServices/BTS_FT_GetFireStatus.h"
#include "GameFramework\Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BasePawn/FriendlyPawn/FriendlyCharacterBaseTank/FriendlyCharacterTank/FriendlyCharacterTank.h"

UBTS_FT_GetFireStatus::UBTS_FT_GetFireStatus()
{
	NodeName = TEXT("Get FriendlyTank Fire Status");
}

void UBTS_FT_GetFireStatus::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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

    if (Cast<AFriendlyCharacterTank>(OwnerPawn))
    {
        bool FireStatus = Cast<AFriendlyCharacterTank>(OwnerPawn)->IsReadyForFire();

        OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), FireStatus);

    }

}
