// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeServices/BTS_FT_UpdatePlayerTankIfSeen.h"
#include "GameFramework\Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/PlayerTank/PlayerTank.h"
#include "Kismet/GameplayStatics.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyTank/FriendlyTank.h"

UBTS_FT_UpdatePlayerTankIfSeen::UBTS_FT_UpdatePlayerTankIfSeen()
{
	NodeName = TEXT("FT Update Player Tank If Seen");
}

void UBTS_FT_UpdatePlayerTankIfSeen::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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
    //
    //if (OwnerPawn)
    //{
    //    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    //    OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);

    //}
    //

    if (Cast<AFriendlyTank>(OwnerPawn))
    {
        AActor* TargetActor = Cast<AFriendlyTank>(OwnerPawn)->FindClosestPlayer();
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
