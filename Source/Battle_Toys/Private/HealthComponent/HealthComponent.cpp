// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent/HealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Battle_Toys/Battle_ToysGameModeBase.h"

// Sets default values for this component's properties
UHealthComponent::UHealthComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UHealthComponent::AddHealthFromUpgrade(float HealingValue)
{
	if (HealingValue)
	{
		CurrentHealth += HealingValue;
	}
	if (CurrentHealth >= MaxHealth)
	{
		CurrentHealth = MaxHealth;
	}
	UE_LOG(LogTemp, Warning, TEXT("Healing from Uppgrade! CurrentHealth: %f"), CurrentHealth);
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	BattleToysGameMode = Cast<ABattle_ToysGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));

	CurrentHealth = MaxHealth;

	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::DamageTaken);
;
}


// Called every frame
void UHealthComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UHealthComponent::DamageTaken(
	AActor* DamagedActor,
	float Damage, 
	const UDamageType* DamageType, 
	AController* Instigator, 
	AActor* DamageCauser)
{
	if (Damage <= 0.f)
	{
		return;
	}

	CurrentHealth -= Damage;
	UE_LOG(LogTemp, Warning, TEXT("CurrentHealth: %f"), CurrentHealth);
	if (CurrentHealth <= 0.f && BattleToysGameMode)
	{
		BattleToysGameMode->PawnKilled(DamagedActor);
	}
}

