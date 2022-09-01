// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseUpgradePlayerTank/UpgradeSpeedPlayerTank/UpgradeSpeedPlayerTank.h"
#include "BasePawn/FriendlyPawn/FriendlyBaseTank/PlayerTank/PlayerTank.h"
#include "Kismet/GameplayStatics.h"

void AUpgradeSpeedPlayerTank::OnOverlapBegin(
	UPrimitiveComponent* OverlappedComp, 
	AActor* OtherActor, 
	UPrimitiveComponent* OtherComp, 
	int32 OtherBodyIndex,
	bool bFromSweep, 
	const FHitResult& SweepResult)
{
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr))
	{
		if (Cast<APlayerTank>(OtherActor))
		{
			APlayerTank* PlayerTank = Cast<APlayerTank>(OtherActor);
			PlayerTank->SetSpeedUpgrade(UpgradeTankSpeedMultiplier);
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
