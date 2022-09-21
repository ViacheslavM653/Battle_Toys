// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn/EnemyPawn/BaseEnemyTank/BaseEnemyTank.h"
#include "EnemyTank.generated.h"

class ABaseUpgradePlayerTank;

/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API AEnemyTank : public ABaseEnemyTank
{
	GENERATED_BODY()
	
public:

    // Called every frame
    virtual void Tick(float DeltaTime) override;
    /** Find closest Enemy pawn and turn Tower to his location */
    virtual AActor* FindClosestTarget();
    /** Get condition for start Fire */
    virtual bool bStartFire();
    //Pawn Destruction
    virtual void HandleDestruction() override;

    bool IsReadyForFire();



protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

    AActor* TargetToShot;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
        float SearchTargetRadius = 1000.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Combat", meta = (AllowPrivateAccess = "true"))
        float FireRange = 500.f;

    bool ShoodFire = false;
private:

    UPROPERTY(EditAnywhere, Category = "UpgradePlayerTank")
        TSubclassOf<ABaseUpgradePlayerTank> UpgradePlayerTankClass;



};
