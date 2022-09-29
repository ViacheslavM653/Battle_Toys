// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/FriendlyBaseTank.h"
#include "FriendlyTank.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API AFriendlyTank : public AFriendlyBaseTank
{
	GENERATED_BODY()
	

public:
 
    // Called every frame
    virtual void Tick(float DeltaTime) override;
    /** Find closest Enemy pawn and turn Tower to his location */
    virtual AActor* FindClosestTarget();
    /** Find closest Player pawn and turn Tower to his location */
    virtual AActor* FindClosestPlayer();
    /** Get condition for start Fire */
    virtual bool bStartFire();



protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    AActor* TargetToShot;
    AActor* PlayerTankTarget;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
    float SearchTargetRadius = 1000.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
    float FireRange = 500.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
        float SearchPlayerRadius = 3000.f;

 
private:


};
