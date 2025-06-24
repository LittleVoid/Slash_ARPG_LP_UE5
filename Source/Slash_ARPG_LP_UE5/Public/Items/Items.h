// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Items.generated.h"

UCLASS()
class SLASH_ARPG_LP_UE5_API AItems : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItems();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;


};
