// Fill out your copyright notice in the Description page of Project Settings.


#include "BatleTankPlayerController/BatleTankPlayerController.h"
#include "Blueprint/UserWidget.h"


void ABatleTankPlayerController::BeginPlay()
{
	Super::BeginPlay();

	SetPlayerEnabledState(true);

	if (IsValid(HUDClass))
	{
		HUD = CreateWidget(this, HUDClass);
		if (HUD != nullptr)
		{
			HUD->AddToViewport();
		}
	}
	
	
	
	
}

void ABatleTankPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);
	if (bIsWinner)
	{
		UUserWidget* WinScreen = CreateWidget(this, WinSceenClass);
		if (WinScreen != nullptr)
		{
			SetPlayerEnabledState(false);
			WinScreen->AddToViewport();
		}
	}
	else
	{
		UUserWidget* LosseScreen = CreateWidget(this, LoseScreenClass);
		if (LosseScreen != nullptr)
		{
			SetPlayerEnabledState(bIsWinner);
			if (HUD != nullptr)
			{
				HUD->RemoveFromViewport();
			}
			bShowMouseCursor = false;
			LosseScreen->AddToViewport();
		}
	}
}

void ABatleTankPlayerController::SetPlayerEnabledState(bool bPlayerEnabled)
{
	if (bPlayerEnabled)
	{
		GetPawn()->EnableInput(this);
	}
	else
	{
		GetPawn()->DisableInput(this);
		
	}
	bShowMouseCursor = bPlayerEnabled;
}

