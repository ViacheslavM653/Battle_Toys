// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn/FriendlyPawn/FriendlyPawn.h"
#include "FriendlyBaseTank.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;
class UFloatingPawnMovement;

/**
 * BaseFrendlyTank class
 */
UCLASS()
class BATTLE_TOYS_API AFriendlyBaseTank : public AFriendlyPawn
{
    GENERATED_BODY()

public:
    // Sets default values for this pawn's properties
    AFriendlyBaseTank();


    /*---------Start------------Temp Block----------------Start------------------*/


    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

    void Move(float AxisValue);

    /** Find Vector for Move() function use Ground */
    FVector FindMovementInputVector(float AxisValue);

    void Turn(float AxisValue);


    /*---------End------------Temp Block----------------End------------------*/



    // Called every frame
    virtual void Tick(float DeltaTime) override;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    /** Funcrion for rotation Tank Hull by terain */
    virtual void SetupTankOnGround();

    /** Spawn Projectile and Produce Shot  */
    void Fire();

    /** If an EnemyPawn is found - rotate TankTower to the Enemy location
    * @param LookAtTarget - Enemy location
    */
    virtual void RotateTankTowerToEnemy(FVector& LookAtTarget);
    /**  TankTower follow to the Enemy
    * @param LookAtTarget - Enemy location
    */
    virtual void TurnTankTowerToEnemy(FVector& LookAtTarget);

private:
    /**Calculated Position for Tank by tracing ground */
    void SetStartTankPositionByTerrain();
    /** AsyncLineTraceByChannel by Visibility
    * @param StartLocation - Location form start tracing;
    * @param DepthTracingValue - depth value. */
    FHitResult GetTracingResultByVisibility(FVector& StartLocation, float& DepthTracingValue);
    /** Calculate Pitch value from HitResult relative ActorRotation
    * @param HitResult - TracingResult.
    */
    float GetPitchFromHitNormal(FHitResult& HitResult);
    /** Calculate Roll value from HitResult relative ActorRotation
    * @param HitResult - TracingResult.
    */
    float GetRollFromHitNormal(FHitResult& HitResult);

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank Component", meta = (AllowPrivateAccess = "true"))
        UCapsuleComponent* CapsuleComponent;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank Pivot", meta = (AllowPrivateAccess = "true"))
        USceneComponent* TankPivot;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank ForwardRightWheel Sensor ", meta = (AllowPrivateAccess = "true"))
        USceneComponent* ForwardRightWheelSensor;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank ForwardLeftWheel Sensor ", meta = (AllowPrivateAccess = "true"))
        USceneComponent* ForwardLeftWheelSensor;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank BackwardRightWheel Sensor ", meta = (AllowPrivateAccess = "true"))
        USceneComponent* BackwardRightWheelSensor;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank BackwardLeftWheel Sensor ", meta = (AllowPrivateAccess = "true"))
        USceneComponent* BackwardLeftWheelSensor;

    UPROPERTY(EditAnywhere, Category = "Tank Mesh")
        USkeletalMeshComponent* TankHullSkeletalMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank Mesh", meta = (AllowPrivateAccess = "true"))
        UStaticMeshComponent* TankLeftTrackMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank Mesh", meta = (AllowPrivateAccess = "true"))
        UStaticMeshComponent* TankRightTrackMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank Mesh", meta = (AllowPrivateAccess = "true"))
        UStaticMeshComponent* TankTowerMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank Mesh", meta = (AllowPrivateAccess = "true"))
        UStaticMeshComponent* TankBarrelMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank Mesh", meta = (AllowPrivateAccess = "true"))
        USceneComponent* ProjectileSpawnPoint;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
        UFloatingPawnMovement* MovementComponent;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
        float TurnTankTowerInterpolationSpeed = 5.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
        float TurnRate = 50.f;

};
