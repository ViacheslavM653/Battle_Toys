// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BasePawn.generated.h"

class ABattleToysProjectile;
class UHealthComponent;

UCLASS()
class BATTLE_TOYS_API ABasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABasePawn();
	/** Triger for UHealthComponent->AddHealthFromUpgrade(float HealingValue) */
	virtual void AddHealthFromUpgrade(float HealingValue);
	/**Get float value ProjectileDamage */
	float GetProjectileDamage();
	/**Get float value ProjectileSpeed */
	float GetProjectileSpeed();
	/** Update float  value ProjectileDamage 
	*Multiple ProjectileDamage by UpgradeProjectileDamageMultiplier
	*/
	virtual void SetUpgradeForProjectileDamage(float UpgradeProjectileDamageMultiplier);
	/** Update float  value ProjectileSpeed
	*Multiple ProjectileSpeed by UpgradeProjectileSpeedMultiplier
	*/
	virtual void SetUpgradeForProjectileSpeed(float UpgradeProjectileSpeedMultiplier);


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Projectile")
	TSubclassOf<ABattleToysProjectile> ProjectileClass;

	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	//Pawn Destruction
	void HandleDestruction();
	/** Set to: @param bPawnAlive - value "false" */
	void SetPawnDie();
	/** Get bool value from @param bPawnAlive */
	bool IsPawnAlive();

	

protected:

	UPROPERTY(EditAnywhere, Category = "Projectile")
	float ProjectileDamage = 30.f;
	
	UPROPERTY(EditAnywhere, Category = "Projectile")
	float ProjectileSpeed = 1300.f;

	UPROPERTY(EditAnywhere, Category = "Health")
	UHealthComponent* HealthComponent;

	

private:
	
	/**Sratus Pawn: true / false */
	bool bPawnAlive;
	


	UPROPERTY(EditAnywhere, Category = "Death")
	UParticleSystem* DeathParticles;

	UPROPERTY(EditAnywhere, Category = "Death")
	USoundBase* DeathSound;

	UPROPERTY(EditAnywhere, Category = "Death")
	TSubclassOf<UCameraShakeBase> DeathCameraShakeClass;
};
