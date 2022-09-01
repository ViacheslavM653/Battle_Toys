// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseUpgradePlayerTank.generated.h"

class UCapsuleComponent;
class UParticleSystem;

UCLASS()
class BATTLE_TOYS_API ABaseUpgradePlayerTank : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseUpgradePlayerTank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


	UPROPERTY(EditAnywhere, Category = "Overlaped Sound")
		USoundBase* OverlapedSound;

	UPROPERTY(EditAnywhere, Category = "Overlaped Particles")
		UParticleSystem* OverlapedParticles;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "Moving", BlueprintReadWrite)
		bool ActivatedMovement = true;

	UFUNCTION()
		virtual void OnOverlapBegin(
			class UPrimitiveComponent* OverlappedComp,
			class AActor* OtherActor,
			class UPrimitiveComponent* OtherComp, 
			int32 OtherBodyIndex, bool bFromSweep, 
			const FHitResult& SweepResult);

private:
	UPROPERTY(VisibleAnywhere, Category = "Trigger Capsule")
		UCapsuleComponent* TriggerCapsule;

	UPROPERTY(VisibleAnywhere, Category = "Upgrade Mesh")
		UStaticMeshComponent* UpgradeMesh;

	UPROPERTY(EditAnywhere, Category = "Moving")
		FVector PlatformVelocity = FVector(0, 0, 100);

	UPROPERTY(EditAnywhere, Category = "Moving")
		float MoveDistance = 100;

	UPROPERTY(EditAnywhere, Category = "Moving")
		FRotator RotatorVelocity;

	FVector StartLocation;

	void MovePlatform(float DeltaTime);
	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;

	void RotatePlatform(float DeltaTime);
};
