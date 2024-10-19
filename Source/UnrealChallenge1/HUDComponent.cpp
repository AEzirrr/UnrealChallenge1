// Fill out your copyright notice in the Description page of Project Settings.


#include "HUDComponent.h"
#include "Components/ProgressBar.h"
#include "Components/TextBlock.h"

void UHUDComponent::NativeConstruct()
{
    Super::NativeConstruct();

    // Example: Setting initial stone and wood values
    float InitialStone = 50.f;
    float MaxStone = 100.f;

    SetStone(InitialStone, MaxStone);
    SetWood(InitialStone, MaxStone);
    UpdateText(activeSilos, 3.f);
}

void UHUDComponent::SetStone(float CurrentStone, float MaxStone)
{
    UpdateProgressBar(StoneBar, CurrentStone, MaxStone);
    UpdateText(maxStone, MaxStone);
    UpdateText(currentStone, CurrentStone);
}

void UHUDComponent::SetWood(float CurrentWood, float MaxWood)
{
    UpdateProgressBar(WoodBar, CurrentWood, MaxWood);
    UpdateText(maxWood, MaxWood);
    UpdateText(currentWood, CurrentWood);
}

void UHUDComponent::UpdateProgressBar(UProgressBar* ProgressBar, float Current, float Max)
{
    if (ProgressBar)
    {
        ProgressBar->SetPercent(Current / Max);
    }
}

void UHUDComponent::UpdateText(UTextBlock* TextBlock, float Value)
{
    if (TextBlock)
    {
        TextBlock->SetText(FText::FromString(FString::Printf(TEXT("%d"), static_cast<int32>(Value))));
    }
}

