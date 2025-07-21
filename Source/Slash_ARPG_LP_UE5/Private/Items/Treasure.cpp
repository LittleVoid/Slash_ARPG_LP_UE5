// Fill out your copyright notice in the Description page of Project Settings.


#include "Items/Treasure.h"
#include "Characters/SlashCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SphereComponent.h"



ATreasure::ATreasure() : Super()
{
	AItem::Sphere->SetSphereRadius(75.f);
}

void ATreasure::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ASlashCharacter* SlashChacter = Cast<ASlashCharacter>(OtherActor);
		if (SlashChacter)
		{
			if (PickUpSound)
			{
				UGameplayStatics::PlaySoundAtLocation(this, PickUpSound, GetActorLocation());

			}
			Destroy();
		}
}
