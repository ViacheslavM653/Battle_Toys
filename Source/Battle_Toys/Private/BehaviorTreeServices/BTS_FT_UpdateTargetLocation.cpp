// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeServices/BTS_FT_UpdateTargetLocation.h"
#include "GameFramework\Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyTank/FriendlyTank.h"
#include "NavigationSystem.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/PlayerTank/PlayerTank.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyTank/HostageTank/HostageTank.h"

UBTS_FT_UpdateTargetLocation::UBTS_FT_UpdateTargetLocation()
{
	NodeName = TEXT("FT Update Target Location");
}

void UBTS_FT_UpdateTargetLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
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
    if (Cast<AFriendlyTank>(OwnerPawn))
    {
        if (Cast<AHostageTank>(OwnerPawn))
        {
            if (!Cast<AHostageTank>(OwnerPawn)->GetHostageFreeStatus())
            {
                return;
            }
        }
        AActor* TargetActor = Cast<AFriendlyTank>(OwnerPawn)->FindClosestPlayer();

        if (TargetActor)
        {
            //Randomness Location
            FVector Origin = TargetActor->GetActorLocation();
            float Radius = 400.f;
            FNavLocation ResultLocation;
            UNavigationSystemV1* NavigationArea;
            FVector TargetLocation = NavigationArea->GetRandomPointInNavigableRadius(GetWorld(), Origin, Radius);
            //
            OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), TargetLocation);
        }
        else
        {
            return;
        }


    }
}
