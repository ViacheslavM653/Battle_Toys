// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BaseDestructibleActor.generated.h"

class UBoxComponent;
class UHealthComponent;

UCLASS()
class BATTLE_TOYS_API ABaseDestructibleActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABaseDestructibleActor();

	//Pawn Destruction
	virtual void HandleDestruction();

	/** Set to: @param bPawnAlive - value "false" */
	void SetPawnDie();
	/** Get bool value from @param bPawnAlive */
	bool IsPawnAlive();
	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Health")
		UHealthComponent* HealthComponent;

	UPROPERTY(EditAnywhere, Category = "Death")
		UParticleSystem* DeathParticles;

	UPROPERTY(EditAnywhere, Category = "Death")
		USoundBase* DeathSound;

	UPROPERTY(EditAnywhere, Category = "Death")
		TSubclassOf<UCameraShakeBase> DeathCameraShakeClass;


private:

	UPROPERTY(VisibleAnywhere, Category = "Tank Component")
		UBoxComponent* BoxComponent;

	UPROPERTY(EditAnywhere, Category = "Tower Mesh")
		UStaticMeshComponent* Mesh;

	/**Sratus Pawn: true / false */
	bool bPawnAlive;

};
