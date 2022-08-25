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
    // Called to bind functionality to input
    virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
    /** Float value for animation rate (from -1 to 1) */
    UFUNCTION(BlueprintPure)
    float GetRightWheelsAnimationSpeed();
    /** Float value for animation rate (from -1 to 1) */
    UFUNCTION(BlueprintPure)
    float GetLeftWheelsAnimationSpeed();

    // Called every frame
    virtual void Tick(float DeltaTime) override;

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;
    /** Funcrion for rotation Tank Hull by terain */
    virtual void SetupTankOnGround();

    /** Spawn Projectile and Produce Shot  */
    void Fire();

    /** Move Tank by PlayerInput */
    void Move(float AxisValue);
    /** Value from PlayerInput */
    float MoveForwardValue;
    /** Find Vector for Move() function use Ground */
    FVector FindMovementInputVector(float AxisValue);
    /** Turn Tank by PlayerInput */
    void Turn(float AxisValue);
       
    /**  TankTower follow to the Enemy
    * @param LookAtTarget - Enemy location
    */
    virtual void TurnTankTowerToEnemy(FVector& LookAtTarget);

private:
    
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
    /** Storage TankRotation.Yaw to TankRotationHistoryArray */
    void StorageActorRotation(int32 StorageDepth);

    /**  Get Value TankSpeedRate (from 0 to 1) for amimation */
    virtual float GetTankSpeedRateForAnimation();
    /** Get Value TankTurnRate (from 0 to 1) for amimation */
    virtual float GetTankTurnRightForAnimation();

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
        float SuspensionHardness = 10.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
        float TurnRate = 50.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation", meta = (AllowPrivateAccess = "true"))
        float TankWheelAnimationSpeedMultiplier = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation", meta = (AllowPrivateAccess = "true"))
        float TankTrackAnimationSpeedMultiplier = 1;

    /** Variable for store TrackRightPosition in Green channel (TexCoordiant) */
    float TankTrackRightPosition = 0;
    /** Variable for store TrackLeftPosition in Green channel (TexCoordiant) */
    float TankTrackLeftPosition = 0;
    /** Material for dynamic slide RightTankTrack TexCoordiant*/
    UMaterialInstanceDynamic* RightTankTrackDynamicMaterial = nullptr;
    /** Material for dynamic slide LeftTankTrack TexCoordiant*/
    UMaterialInstanceDynamic* LeftTankTrackDynamicMaterial = nullptr;
    
    void CreateDynamicMaterialsInstancesForTankTracks();
      
    /** how many times need to storage TankRotation.Yaw to TankRotationHistoryArray */
    static const uint32 TankRotationHistoryDepth = 10;
     
    TStaticArray<FRotator, TankRotationHistoryDepth>TankRotationHistoryArray;
   
};
