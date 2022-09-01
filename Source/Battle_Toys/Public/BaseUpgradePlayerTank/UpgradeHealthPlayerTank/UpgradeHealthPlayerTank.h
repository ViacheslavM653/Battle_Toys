// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BaseUpgradePlayerTank/BaseUpgradePlayerTank.h"
#include "UpgradeHealthPlayerTank.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API AUpgradeHealthPlayerTank : public ABaseUpgradePlayerTank
{
	GENERATED_BODY()
	
public:

	virtual void OnOverlapBegin(
		class UPrimitiveComponent* OverlappedComp,
		class AActor* OtherActor,
		class UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult) override;

private:

	UPROPERTY(EditAnywhere, Category = "Upgrade Value")
		float UpgradeHealthTankValue = 20.f;

};
