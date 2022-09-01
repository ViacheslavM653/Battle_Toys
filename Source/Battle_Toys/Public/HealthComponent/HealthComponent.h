// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

class ABattleToysGameMode;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_TOYS_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UHealthComponent();
	/*
	* Add Health from pickup UpgradeActor
	* @param HealingValue - value received from UpgradeActor
	*/
	void AddHealthFromUpgrade(float HealingValue);
		

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	/** Holder CurrentGameMode */
	ABattleToysGameMode* BattleToysGameMode;

	/** Value representing the pawn's current health */
	UPROPERTY(VisibleAnywhere)
	float CurrentHealth;

	UPROPERTY(EditAnywhere, Category = "Health")
	float MaxHealth = 100.f;
		
	UFUNCTION()
	void DamageTaken(
			AActor* DamagedActor,
			float Damage,
			const UDamageType* DamageType,
			class AController* Instigator,
			AActor* DamageCauser
		);
};
