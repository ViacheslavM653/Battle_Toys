// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn/FriendlyPawn/FriendlyPawn.h"
#include "FriendlyBaseTower.generated.h"

class UCapsuleComponent;
class UBoxComponent;

/**
 * 
 */
UCLASS()
class BATTLE_TOYS_API AFriendlyBaseTower : public AFriendlyPawn
{
	GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    AFriendlyBaseTower();

    // Called every frame
    virtual void Tick(float DeltaTime) override;
	
    /** Spawn Projectile and Produce Shot  */
    void Fire();
protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;



    /**  TankTower follow to the Enemy
    * @param LookAtTarget - Enemy location
    */
    virtual void TurnTankTowerToEnemy(FVector& LookAtTarget);

private:


    //Creating Hirarchical Structure
    UPROPERTY(VisibleAnywhere, Category = "Tower Component")
        UCapsuleComponent* CapsuleComponent;

    UPROPERTY(VisibleAnywhere, Category = "Tank Component")
        UBoxComponent* BoxComponent;

    UPROPERTY(EditAnywhere, Category = "Tower Mesh")
        UStaticMeshComponent* TowerHullMesh;

    UPROPERTY(VisibleAnywhere, Category = "Tower Mesh")
        UStaticMeshComponent* TowerTowerMesh;

    UPROPERTY(VisibleAnywhere, Category = "Tower Mesh")
        UStaticMeshComponent* TowerBarrelMesh;

    UPROPERTY(VisibleAnywhere, Category = "Tower Component")
        USceneComponent* ProjectileSpawnPoint;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
        float TurnTowerTowerInterpolationSpeed = 5.f;

};
