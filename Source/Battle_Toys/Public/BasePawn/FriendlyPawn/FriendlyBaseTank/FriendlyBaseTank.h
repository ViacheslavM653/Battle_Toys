// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn/FriendlyPawn/FriendlyPawn.h"
#include "FriendlyBaseTank.generated.h"

class UCapsuleComponent;
class USkeletalMeshComponent;
class UFloatingPawnMovement;
class UNiagaraComponent;

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
    //Creating Hirarchical Structure

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation", meta = (AllowPrivateAccess = "true"))
        float TankWheelAnimationSpeedMultiplier = 1;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation", meta = (AllowPrivateAccess = "true"))
        float TankTrackAnimationSpeedMultiplier = 1;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
        UFloatingPawnMovement* MovementComponent;

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

    
    float TankSpeedRateForAnimation;
    /**  Get Value TankSpeedRate (from 0 to 1) for amimation */
    virtual void GetTankSpeedRateForAnimation();
    
    float TankTurnRightForAnimation;
    /** Get Value TankTurnRate (from 0 to 1) for amimation */
    virtual void GetTankTurnRightForAnimation();


    UPROPERTY(VisibleAnywhere, Category = "Tank Component")
        UCapsuleComponent* CapsuleComponent;
    
    UPROPERTY(VisibleAnywhere,  Category = "Tank Pivot")
        USceneComponent* TankPivot;

    UPROPERTY(VisibleAnywhere,  Category = "Tank ForwardRightWheel Sensor ")
        USceneComponent* ForwardRightWheelSensor;

    UPROPERTY(VisibleAnywhere,  Category = "Tank ForwardLeftWheel Sensor ")
        USceneComponent* ForwardLeftWheelSensor;

    UPROPERTY(VisibleAnywhere,  Category = "Tank BackwardRightWheel Sensor ")
        USceneComponent* BackwardRightWheelSensor;

    UPROPERTY(VisibleAnywhere,  Category = "Tank BackwardLeftWheel Sensor ")
        USceneComponent* BackwardLeftWheelSensor;

    UPROPERTY(EditAnywhere, Category = "Tank Mesh")
        USkeletalMeshComponent* TankHullSkeletalMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Exhaust Particles", meta = (AllowPrivateAccess = "true"))
        UNiagaraComponent* RightExhaustNPS;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Exhaust Particles", meta = (AllowPrivateAccess = "true"))
        UNiagaraComponent* LeftExhaustNPS;

    UPROPERTY(VisibleAnywhere, Category = "Tank Mesh")
        UStaticMeshComponent* TankLeftTrackMesh;

    UPROPERTY(VisibleAnywhere,  Category = "Tank Mesh")
        UStaticMeshComponent* TankRightTrackMesh;

    UPROPERTY(VisibleAnywhere,  Category = "Tank Mesh")
        UStaticMeshComponent* TankTowerMesh;

    UPROPERTY(VisibleAnywhere,  Category = "Tank Mesh")
        UStaticMeshComponent* TankBarrelMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank Mesh", meta = (AllowPrivateAccess = "true"))
        USceneComponent* ProjectileSpawnPoint;


    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
        float TurnTankTowerInterpolationSpeed = 5.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
        float SuspensionHardness = 10.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
        float TurnRate = 50.f;


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

    float RightWheelsAction;
    float LeftWheelsAction;
   
    UPROPERTY(EditAnywhere, Category = "Exhaust Particles", meta = (AllowPrivateAccess = "true"))
        float ExhaustIdleVelocitySpeed = 300.f;

    UPROPERTY(EditAnywhere, Category = "Exhaust Particles", meta = (AllowPrivateAccess = "true"))
        float ExhaustMaxVelocitySpeed = 900.f;

    UPROPERTY(EditAnywhere, Category = "Exhaust Particles", meta = (AllowPrivateAccess = "true"))
        float ExhaustIdleSpawnRate = 60.f;

    UPROPERTY(EditAnywhere, Category = "Exhaust Particles", meta = (AllowPrivateAccess = "true"))
        float ExhaustMaxSpawnRate = 600.f;

    /** Dynamicly set parameters for RightExhaustNPS and LeftExhaustNPS 
    * @param IdleVelocitySpeed - value when tank not move;
    * @param IdleSpawnRate - value when tank mot move.
    * @param MaxVelocitySpeed - value when tank move;
    * @param MaxSpawnRate - value when tank move.
    */
    void SetTankExhaustNiagaraParticles(
        float IdleVelocitySpeed, 
        float IdleSpawnRate, 
        float MaxVelocitySpeed, 
        float MaxSpawnRate
    );

    UPROPERTY(EditAnywhere, Category = "Exhaust Sound")
    USoundBase* TankIdleSound;
    UAudioComponent* TankIdleSoundComponent;

    UPROPERTY(EditAnywhere, Category = "Exhaust Sound")
    USoundBase* TankAccelerationSound;
    UAudioComponent* TankAccelerationSoundComponent;

    //FTimerHandle ExhaustSoundTimerHandle;
    void CreateExhaustSoundComponents();
    void PlayExhaustSound();
   
};
