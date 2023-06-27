// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "FriendlyCharacterBaseTank.generated.h"

class ABattleToysProjectile;
class UHealthComponent;
class UNiagaraComponent;
class UBoxComponent;
class UOutlineMaterialComponent;

UCLASS()
class BATTLE_TOYS_API AFriendlyCharacterBaseTank : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AFriendlyCharacterBaseTank();
   
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	////////////////////////////////////////////////////////////////////////////
	////////////////// Start:  Functional from BasePawn ////////////////////////
	UPROPERTY(EditAnywhere, Category = "Projectile")
		TSubclassOf<ABattleToysProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, Category = "Health")
		UHealthComponent* HealthComponent;

    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
    //++++++++++++++ Start:  Functional Outline shader and Freindly sprite for FriendlyBaseTank +++++++++++++++++//

    UPROPERTY(EditAnywhere, Category = "OutlineMaterial")
        UOutlineMaterialComponent* OutlineMaterialComponent;

    //++++++++++++++ End:  Functional Outline shader and Freindly sprite for FriendlyBaseTank ++++++++++++++++++//
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


	UPROPERTY(EditAnywhere, Category = "Death")
		UParticleSystem* DeathParticles;

	UPROPERTY(EditAnywhere, Category = "Death")
		USoundBase* DeathSound;

	UPROPERTY(EditAnywhere, Category = "Death")
		TSubclassOf<UCameraShakeBase> DeathCameraShakeClass;
	////////////////// End:    Functional from BasePawn ////////////////////////
	////////////////////////////////////////////////////////////////////////////
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character)
        TObjectPtr<USkeletalMeshComponent> TankHullSkeletalMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character)
        TObjectPtr<UStaticMeshComponent> TankLeftTrackMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character)
        TObjectPtr<UStaticMeshComponent> TankRightTrackMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character)
        TObjectPtr<UStaticMeshComponent> TankTowerMesh;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Character)
        TObjectPtr<UStaticMeshComponent> TankBarrelMesh;

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	//++++++++++++++ Start:  Functional from FriendlyBaseTank +++++++++++++++++//

	/** Funcrion for rotation Tank Hull by terain */
	virtual void SetupTankOnGround();


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

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank Mesh", meta = (AllowPrivateAccess = "true"))
		USceneComponent* ProjectileSpawnPoint;


	//++++++++++++++ End:  Functional from FriendlyBaseTank ++++++++++++++++++//
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


    //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
    //++++++++++++++ Start:  Functional Outline shader and Freindly sprite for FriendlyBaseTank +++++++++++++++++//
    UFUNCTION(BlueprintPure)
    bool GetTraceFriendlyActorStatus();

    void UpdateTraceFriendlyActorStatus(const bool traceStatus);
     
    //++++++++++++++ End:  Functional Outline shader and Freindly sprite for FriendlyBaseTank ++++++++++++++++++//
    //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


	////////////////////////////////////////////////////////////////////////////
	////////////////// Start:  Functional from BasePawn ////////////////////////

   /** Triger for UHealthComponent->AddHealthFromUpgrade(float HealingValue) */
	virtual void AddHealthFromUpgrade(float HealingValue);
	/** HealthRate for UI */
	UFUNCTION(BlueprintPure)
		float GetHealthRate();

	//Pawn Destruction
	virtual void HandleDestruction();
	/** Set to: @param bPawnAlive - value "false" */
	void SetPawnDie();
	/** Get bool value from @param bPawnAlive */
	bool IsPawnAlive();

	////////////////// End:    Functional from BasePawn ////////////////////////
	////////////////////////////////////////////////////////////////////////////

	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	//++++++++++++++ Start:  Functional from FriendlyBaseTank +++++++++++++++++//

	/** Float value for animation rate (from -1 to 1) */
	UFUNCTION(BlueprintPure)
		float GetRightWheelsAnimationSpeed();
	/** Float value for animation rate (from -1 to 1) */
	UFUNCTION(BlueprintPure)
		float GetLeftWheelsAnimationSpeed();

	/** TurnActor if Velocity magnitude > 0*/
	void TurnActorAccordingToVelocity();

	/** Spawn Projectile and Produce Shot  */
	virtual void Fire();

	//++++++++++++++ End:  Functional from FriendlyBaseTank ++++++++++++++++++//
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//

private:

	////////////////////////////////////////////////////////////////////////////
	////////////////// Start:  Functional from BasePawn ////////////////////////
	/**Sratus Pawn: true / false */
	bool bPawnAlive;
	////////////////// End:    Functional from BasePawn ////////////////////////
	////////////////////////////////////////////////////////////////////////////


	//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//
	//++++++++++++++ Start:  Functional from FriendlyBaseTank +++++++++++++++++//

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
        TObjectPtr<UBoxComponent> BoxComponent;

    UPROPERTY(VisibleAnywhere, Category = Character)
        TObjectPtr<USceneComponent> TankPivot;

    UPROPERTY(VisibleAnywhere, Category = "Tank ForwardRightWheel Sensor ")
        TObjectPtr <USceneComponent> ForwardRightWheelSensor;

    UPROPERTY(VisibleAnywhere, Category = "Tank ForwardLeftWheel Sensor ")
        TObjectPtr<USceneComponent> ForwardLeftWheelSensor;

    UPROPERTY(VisibleAnywhere, Category = "Tank BackwardRightWheel Sensor ")
        TObjectPtr<USceneComponent> BackwardRightWheelSensor;

    UPROPERTY(VisibleAnywhere, Category = "Tank BackwardLeftWheel Sensor ")
        TObjectPtr<USceneComponent> BackwardLeftWheelSensor;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Exhaust Particles", meta = (AllowPrivateAccess = "true"))
        TObjectPtr<UNiagaraComponent> RightExhaustNPS;

    UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Exhaust Particles", meta = (AllowPrivateAccess = "true"))
        TObjectPtr<UNiagaraComponent> LeftExhaustNPS;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
        float TurnTankTowerInterpolationSpeed = 5.f;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement", meta = (AllowPrivateAccess = "true"))
        float TurnTankInterpolationSpeed = 5.f;

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

	//++++++++++++++ End:  Functional from FriendlyBaseTank ++++++++++++++++++//
	//++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++//


};
