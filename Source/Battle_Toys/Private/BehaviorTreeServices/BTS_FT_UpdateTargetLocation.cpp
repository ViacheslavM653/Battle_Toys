// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeServices/BTS_FT_UpdateTargetLocation.h"
#include "GameFramework\Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BasePawn/FriendlyPawn/FriendlyCharacterBaseTank/FriendlyCharacterTank/FriendlyCharacterTank.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/PlayerTank/PlayerTank.h"
#include "BasePawn/FriendlyPawn/FriendlyCharacterBaseTank/FriendlyCharacterTank/FriendlyHostageCharacterTank/FriendlyHostageCharacterTank.h"

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
    
    if (Cast<AFriendlyCharacterTank>(OwnerPawn))
    {
        
        if (Cast<AFriendlyHostageCharacterTank>(OwnerPawn))
        {
            if (!Cast<AFriendlyHostageCharacterTank>(OwnerPawn)->GetHostageFreeStatus())
            {
                return;
            }
        }
        AActor* TargetActor = Cast<AFriendlyCharacterTank>(OwnerPawn)->FindClosestPlayer();

        if (TargetActor)
        {
            //Randomness Location
            FVector Origin = TargetActor->GetActorLocation();
            float Radius = 300.f;
   /*         ANavigationData* NavigationData;
            FNavLocation OutResult;*/
            //UNavigationSystemV1* NavigationArea;
            //FVector TargetLocation = NavigationArea->GetRandomPointInNavigableRadius(GetWorld(), Origin, Radius);

            //
            OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), Origin);
        }
        else
        {
            return;
        }


    }
}
