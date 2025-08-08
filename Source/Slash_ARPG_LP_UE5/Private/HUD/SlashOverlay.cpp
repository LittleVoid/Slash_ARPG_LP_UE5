// Fill out your copyright notice in the Description page of Project Settings.


#include "HUD/SlashOverlay.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"


void USlashOverlay::SetHealthBarPerfecnt(float Percent)
{
	if (HealthProgressBar)
	{
		HealthProgressBar->SetPercent(Percent);
	}
}

void USlashOverlay::SetStaminaBarPerfecnt(float Percent)
{
	if (StaminaProgressBar)
	{
		StaminaProgressBar->SetPercent(Percent);
	}
}

void USlashOverlay::SetGold(int32 Gold)
{
	if (GoldCountText)
	{
		GoldCountText->SetText(FText::AsNumber(Gold));
	}
}

void
USlashOverlay::SetSouls(int32 Souls)
{
	if (SoulCountText)
	{
		SoulCountText->SetText(FText::AsNumber(Souls));
	}
}
