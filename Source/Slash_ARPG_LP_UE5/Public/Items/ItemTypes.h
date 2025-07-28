#pragma once


UENUM(BlueprintType)
enum class EWieldType : uint8
{
	EWT_None UMETA(DisplayName = "Cant be wield"),
	EWT_OneHanded UMETA(DisplayName = "One Handed"),
	EWT_TwoHanded UMETA(DisplayName = "Two Handed")
};


enum class EItemState : uint8
{
	EIS_Hovering,
	EIS_Equipped,
	EIS_Static
};