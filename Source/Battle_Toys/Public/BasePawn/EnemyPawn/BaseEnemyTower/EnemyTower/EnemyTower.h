// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn/EnemyPawn/BaseEnemyTower/BaseEnemyTower.h"
#include "EnemyTower.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API AEnemyTower : public ABaseEnemyTower
{
	GENERATED_BODY()
	

public:

    // Called every frame
    virtual void Tick(float DeltaTime) override;
    /** Find closest Enemy pawn and turn Tower to his location */
    virtual AActor* FindClosestTarget();
    /** Get condition for start Fire */
    bool bStartFire();

    bool IsReadyForFire();



protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    AActor* TargetToShot;

private:


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
        float SearchTargetRadius = 1000.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
        float FireRange = 500.f;

    bool ShoodFire = false;

};
