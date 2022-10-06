// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn/FriendlyPawn/FriendlyCharacterBaseTank/FriendlyCharacterTank/FriendlyCharacterTank.h"
#include "FriendlyHostageCharacterTank.generated.h"

class UHostageComponent;

/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API AFriendlyHostageCharacterTank : public AFriendlyCharacterTank
{
	GENERATED_BODY()
	

public:

	int32 GetHostageID();

	void SetFreeHostage();

	bool GetHostageFreeStatus();

	/** Find closest Enemy pawn and turn Tower to his location */
	virtual AActor* FindClosestTarget() override;
	/** Get condition for start Fire */
	virtual bool bStartFire() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:

	UPROPERTY(EditAnywhere, Category = "HostageID")
		int32 HostageID = 0;

	bool HostageFreeStatus;

};
