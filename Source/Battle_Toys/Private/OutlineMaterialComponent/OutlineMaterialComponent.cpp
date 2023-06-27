// Fill out your copyright notice in the Description page of Project Settings.


#include "OutlineMaterialComponent/OutlineMaterialComponent.h"

// Sets default values for this component's properties
UOutlineMaterialComponent::UOutlineMaterialComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	isTraceFriendlyActor = false;
	// ...
}


// Called when the game starts
void UOutlineMaterialComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UOutlineMaterialComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

bool UOutlineMaterialComponent::GetTraceFriendlyActorStatus()
{
	return isTraceFriendlyActor;
}

void UOutlineMaterialComponent::SetTraceFriendlyActor(const bool traceValue)
{
	if (traceValue == true)
	{
		isTraceFriendlyActor = true;
	}
	else
	{
		isTraceFriendlyActor = false;
	}
}

