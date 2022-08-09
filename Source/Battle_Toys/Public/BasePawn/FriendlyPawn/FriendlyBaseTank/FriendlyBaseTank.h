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

	
protected:
	/** Spawn Projectile and Produce Shot  */
	void Fire();

private:

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Tank Component", meta = (AllowPrivateAccess = "true"))
	UCapsuleComponent* CapsuleComponent;

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

};
