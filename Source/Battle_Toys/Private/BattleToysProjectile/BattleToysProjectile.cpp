// Fill out your copyright notice in the Description page of Project Settings.


#include "BattleToysProjectile/BattleToysProjectile.h"

// Sets default values
ABattleToysProjectile::ABattleToysProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABattleToysProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABattleToysProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

