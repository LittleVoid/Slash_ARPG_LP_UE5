// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interfaces/HitInterface.h"
#include "BreakableActor.generated.h"

class UGeometryCollectionComponent;
class UCapsuleComponent;

UCLASS()
class SLASH_ARPG_LP_UE5_API ABreakableActor : public AActor, public IHitInterface
{
	GENERATED_BODY()
	
public:	
	ABreakableActor();

	virtual void Tick(float DeltaTime) override;

	virtual void GetHit_Implementation(const FVector& ImpactPoint) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	UGeometryCollectionComponent* GeometryCollection;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TObjectPtr<UCapsuleComponent> Capsule;

private:

	UPROPERTY(EditAnywhere, Category = "Loot")
	TArray<TSubclassOf<class ATreasure>> TreasureClasses;
	

	bool bBroken = false;

};
