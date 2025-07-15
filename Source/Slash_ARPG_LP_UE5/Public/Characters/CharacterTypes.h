#pragma once

#include "CoreMinimal.h"


UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	ESC_Unequipped UMETA(DisplayName = "Unequipped"),
	ESC_EquippedOneHandedWeapon UMETA(DisplayName = "Equipped OneHandedWeapon"),
	ESC_ESC_EquippedTwoHanedWeapon UMETA(DisplayName = "Equipped TwoHanedWeapon"),
};

UENUM(BlueprintType)
enum class EActionState : uint8
{
	EAS_Unoccupied UMETA(DisplayName = "Unoccupied"),
	EAS_Attacking UMETA(DisplayName = "Attacking"),
	EAS_EquippingWeapon UMETA(DisplayName = "EquippingWeapon")


};