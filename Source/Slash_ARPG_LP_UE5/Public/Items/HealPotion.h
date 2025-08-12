// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Items/Item.h"
#include "HealPotion.generated.h"

/**
 * 
 */
UCLASS()
class SLASH_ARPG_LP_UE5_API AHealPotion : public AItem
{
	GENERATED_BODY()
	
protected:
	virtual void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult) override;

private:

	UPROPERTY(EditAnywhere, Category = "Potion Properties")
	int32 HealPotionAmount;

public:
	FORCEINLINE int32 GetHealPotion() const { return HealPotionAmount; }
	FORCEINLINE void SetHealPotion(int32 NumberOfHealPotion) { HealPotionAmount = NumberOfHealPotion; }
};
