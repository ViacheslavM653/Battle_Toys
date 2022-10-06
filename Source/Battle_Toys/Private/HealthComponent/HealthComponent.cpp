// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthComponent/HealthComponent.h"
#include "Kismet/GameplayStatics.h"
#include "BattleToysGameMode/BattleToysGameMode.h"
#include "BasePawn/FriendlyPawn/FriendlyPawn.h"
#include "BasePawn/EnemyPawn/EnemyPawn.h"

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
	if (HealingValue > 0)
	{
		CurrentHealth += HealingValue;
	}
	if (CurrentHealth >= MaxHealth)
	{
		CurrentHealth = MaxHealth;
	}
	
}

float UHealthComponent::GetHealthRate()
{
	return CurrentHealth/MaxHealth;
}


// Called when the game starts
void UHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	BattleToysGameMode = Cast<ABattleToysGameMode>(UGameplayStatics::GetGameMode(GetWorld()));

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
	//UE_LOG(LogTemp, Warning, TEXT("CurrentHealth : %f"), CurrentHealth);
	if (CurrentHealth <= 0.f)
	{
		//UE_LOG(LogTemp, Warning, TEXT("ActorDied!!"));
		BattleToysGameMode = GetWorld()->GetAuthGameMode<ABattleToysGameMode>();
		if (BattleToysGameMode != nullptr)
		{
			BattleToysGameMode->ActorDied(DamagedActor);

		}
	}
}

