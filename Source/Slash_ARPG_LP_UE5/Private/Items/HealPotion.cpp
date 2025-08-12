// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/HealPotion.h"
#include "Interfaces/PickupInterface.h"


void AHealPotion::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	IPickupInterface* PickupInterface = Cast<IPickupInterface>(OtherActor);
	if (PickupInterface)
	{
		PickupInterface->AddHealPotion(this);
		SpawnPickupSystem();
		SpawnPickupSound();

		Destroy();
	}
}
