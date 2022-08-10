// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BattleToysProjectile.generated.h"

class USoundBase;

UCLASS()
class BATTLE_TOYS_API ABattleToysProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	
	// Sets default values for this actor's properties
	ABattleToysProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:

	
	UPROPERTY(
		VisibleAnywhere,
		BlueprintReadOnly,
		Category = "Combat",
		meta = (AllowPrivateAccess = "true")
	)
	UStaticMeshComponent* ProjectileMesh;

	UPROPERTY(
		VisibleAnywhere,
		BlueprintReadOnly,
		Category = "Movement",
		meta = (AllowPrivateAccess = "true")
	)
	class UProjectileMovementComponent* ProjectileMovementComponent;

	UFUNCTION()
	void OnHit(
			UPrimitiveComponent* HitComp,
			AActor* OtherActor,
			UPrimitiveComponent* OtherComp,
			FVector NormalIpmulse,
			const FHitResult& Hit
		);

	float Damage = 0.f;

	UPROPERTY(EditAnywhere, Category = "Combat")
	class UParticleSystem* HitParticles;

	UPROPERTY(VisibleAnywhere, Category = "Combat")
	class UParticleSystemComponent* TrailParticles;

	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase* LaunchSound;

	UPROPERTY(EditAnywhere, Category = "Combat")
	USoundBase* HitSound;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TSubclassOf<class UCameraShakeBase> HitCameraShakeClass;

};
