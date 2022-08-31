// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyTank/FriendlyTank.h"
#include "HostageTank.generated.h"


class UHostageComponent;
/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API AHostageTank : public AFriendlyTank
{
	GENERATED_BODY()
	
public:
		
	int32 GetHostageID();

	void SetFreeHostage();

	/** Find closest Enemy pawn and turn Tower to his location */
	virtual AActor* FindClosestTarget() override;
	/** Get condition for start Fire */
	virtual bool bStartFire() override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


private:

	UPROPERTY(EditDefaultsOnly, Category = "Hostage Data")
		int32 HostageID = 0;

	bool HostageFreeStatus;
		
};
