#pragma once

UENUM(BlueprintType)
enum class ECharacterState : uint8
{
	ESC_Unequipped UMETA(DisplayName = "Unequipped"),
	ESC_EquippedOneHandedWeapon UMETA(DisplayName = "Equipped OneHandedWeapon"),
	ESC_ESC_EquippedTwoHanedWeapon UMETA(DisplayName = "Equipped TwoHanedWeapon"),
};