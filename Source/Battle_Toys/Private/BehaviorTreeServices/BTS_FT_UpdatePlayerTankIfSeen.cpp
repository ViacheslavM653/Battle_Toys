// Fill out your copyright notice in the Description page of Project Settings.


#include "BehaviorTreeServices/BTS_FT_UpdatePlayerTankIfSeen.h"
#include "GameFramework\Pawn.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIController.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/PlayerTank/PlayerTank.h"
#include "Kismet/GameplayStatics.h"
#include "BasePawn/FriendlyPawn/FriendlyCharacterBaseTank/FriendlyCharacterTank/FriendlyCharacterTank.h"

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
    //UE_LOG(LogTemp, Warning, TEXT("OwnerComp.GetAIOwner()->GetPawn()->GetClass()->GetFullName(): %s"), *OwnerPawn->GetClass()->GetFullName());
    if (OwnerPawn == nullptr)
    {
        return;
    }
    ////////// Start: Temp Part for Test//////////////////

    //if (OwnerPawn)
    //{
    //    APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    //    //UE_LOG(LogTemp, Warning, TEXT("UGameplayStatics::GetPlayerPawn: %s"), *PlayerPawn->GetActorNameOrLabel());
    //    OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), PlayerPawn);
   

    ////////// End: Temp Part for Test//////////////////
    //UE_LOG(LogTemp, Warning, TEXT("OwnerPawn: %s"), *OwnerPawn->GetActorNameOrLabel());

    if (Cast<AFriendlyCharacterTank>(OwnerPawn))
    {
        
        AActor* TargetActor = Cast<AFriendlyCharacterTank>(OwnerPawn)->FindClosestPlayer();
        if (TargetActor)
        {
            if (OwnerComp.GetAIOwner()->LineOfSightTo(TargetActor))
            {
                OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), TargetActor);
                //UE_LOG(LogTemp, Warning, TEXT("TargetActor: %s"), *TargetActor->GetActorNameOrLabel());
            }
            else
            {
                OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
            }
        }

    }

}
