// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseDestructibleActor/BaseDestructibleActor.h"
#include "Components/BoxComponent.h"
#include "HealthComponent/HealthComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
ABaseDestructibleActor::ABaseDestructibleActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	HealthComponent = CreateDefaultSubobject<UHealthComponent>(TEXT("HealthComponent"));

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collider"));
	RootComponent = BoxComponent;
	BoxComponent->SetCollisionProfileName(TEXT("Pawn"));
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(BoxComponent);


}

void ABaseDestructibleActor::HandleDestruction()
{
	if (DeathParticles)
	{
		UGameplayStatics::SpawnEmitterAtLocation(this, DeathParticles, GetActorLocation(), GetActorRotation());
	}
	if (DeathSound)
	{
		UGameplayStatics::PlaySoundAtLocation(this, DeathSound, GetActorLocation());
	}
	if (DeathCameraShakeClass)
	{
		GetWorld()->GetFirstPlayerController()->ClientStartCameraShake(DeathCameraShakeClass);
	}
	SetPawnDie();
	SetActorHiddenInGame(true);
	SetActorTickEnabled(false);
	Destroy();
}

void ABaseDestructibleActor::SetPawnDie()
{
	bPawnAlive = false;
}

bool ABaseDestructibleActor::IsPawnAlive()
{
	return bPawnAlive;
}

// Called when the game starts or when spawned
void ABaseDestructibleActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseDestructibleActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

