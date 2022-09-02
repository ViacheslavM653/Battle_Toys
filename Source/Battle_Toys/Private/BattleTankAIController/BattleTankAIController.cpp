// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleTankAIController/BattleTankAIController.h"
#include "Kismet/GameplayStatics.h"
#include "BehaviorTree/BlackboardComponent.h"

void ABattleTankAIController::BeginPlay()
{
	Super::BeginPlay();

	if (AIBehavior != nullptr)
	{
		RunBehaviorTree(AIBehavior);
		APawn* PlayerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);

		if (GetBlackboardComponent() != nullptr)
		{
			if (GetPawn() != nullptr)
			{
				GetBlackboardComponent()->SetValueAsVector(TEXT("StartLocation"), GetPawn()->GetActorLocation());
			}


		}
	}
}
