// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h"
#include "PlayerTank.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API APlayerTank : public AFriendlyBaseTank
{
	GENERATED_BODY()
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void SetSpeedUpgrade(float Multiplier);
	void SetHealthUpgrade(float AddValue);

	APlayerController* GetPlayerTankController() const;
	
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Bind COmand for Fire and setup Timer  */
	virtual void Fire() override;
	/** Spawn Projectile and Produce Shot  */
	void ActuallyFire(bool FirePermission);

private:
	APlayerController* PlayerTankController;
	/** Set  FireStatus = true */
	void SetFirePermission();

	/** Setup Controll for Tank Tower by mouse controll  */
	void TankTowerControl();

	UPROPERTY(EditAnywhere, Category = "Good Mod")
		bool IsGoodMod = false;

	UPROPERTY(EditAnywhere, Category = "Combat")
		float ShotInverval = 1.f;

	bool FireStatus = true;

	FTimerHandle FireTimerHandle;
};
