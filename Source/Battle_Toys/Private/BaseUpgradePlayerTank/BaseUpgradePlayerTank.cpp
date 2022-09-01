// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseUpgradePlayerTank/BaseUpgradePlayerTank.h"
#include "Components/CapsuleComponent.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/PlayerTank/PlayerTank.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseUpgradePlayerTank::ABaseUpgradePlayerTank()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	TriggerCapsule = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Capsule Collider"));
	TriggerCapsule->SetCollisionObjectType(ECollisionChannel::ECC_Pawn);
	RootComponent = TriggerCapsule;
	TriggerCapsule->OnComponentBeginOverlap.AddDynamic(this, &ABaseUpgradePlayerTank::OnOverlapBegin);

	UpgradeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Upgrade Mesh"));
	UpgradeMesh->SetupAttachment(TriggerCapsule);
}

// Called when the game starts or when spawned
void ABaseUpgradePlayerTank::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	
}



// Called every frame
void ABaseUpgradePlayerTank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);

	RotatePlatform(DeltaTime);

}

void ABaseUpgradePlayerTank::OnOverlapBegin(UPrimitiveComponent* OverlappedComp,
	AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep,
	const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		if (Cast<APlayerTank>(OtherActor))
		{
			
			if (OverlapedParticles)
			{
				UGameplayStatics::SpawnEmitterAtLocation(this, OverlapedParticles, GetActorLocation(), GetActorRotation());
			}
			if (OverlapedSound)
			{
				UGameplayStatics::PlaySoundAtLocation(this, OverlapedSound, GetActorLocation());
			}
			Destroy();
		}
	}
}



void ABaseUpgradePlayerTank::MovePlatform(float DeltaTime)
{
	if (ActivatedMovement)
	{
		//UE_LOG(LogTemp, Display, TEXT("Platform %s -> Start moving "), *GetActorLabel());

		if (ShouldPlatformReturn())
		{
			FVector MoveDirection = PlatformVelocity.GetSafeNormal();
			//Update startLocation
			StartLocation = StartLocation + MoveDirection * MoveDistance;
			SetActorLocation(StartLocation);
			// Reverse direction of motion if gone too far
			PlatformVelocity = -PlatformVelocity;
		}
		else
		{
			FVector CurrentLocation = GetActorLocation();
			CurrentLocation = CurrentLocation + (PlatformVelocity * DeltaTime);
			SetActorLocation(CurrentLocation);
		}
	}

}

bool ABaseUpgradePlayerTank::ShouldPlatformReturn() const
{
	return GetDistanceMoved() > MoveDistance;
}

float ABaseUpgradePlayerTank::GetDistanceMoved() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}

void ABaseUpgradePlayerTank::RotatePlatform(float DeltaTime)
{
	if (ActivatedMovement)
	{
		FRotator CurrentRotation = GetActorRotation();
		CurrentRotation = CurrentRotation + (RotatorVelocity * DeltaTime);
		SetActorRotation(CurrentRotation);
		//UE_LOG(LogTemp, Display, TEXT("Platform %s -> Start rotation! "), *GetActorLabel());
	}

}
