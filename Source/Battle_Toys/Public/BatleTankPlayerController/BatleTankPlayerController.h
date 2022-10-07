// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BatleTankPlayerController.generated.h"


class UUserWidget;
/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API ABatleTankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void GameHasEnded(AActor* EndGameFocus, bool bIsWinner) override;

	void SetPlayerEnabledState(bool bPlayerEnabled);

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> HUDClass;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> WinSceenClass;

	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> LoseScreenClass;

	UPROPERTY()
		UUserWidget* HUD;

	UPROPERTY(EditAnywhere)
		float RestartDelay = 3.f;

	FTimerHandle RestartTimerhandle;
	
};
