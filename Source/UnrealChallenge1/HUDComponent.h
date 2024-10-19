// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "HUDComponent.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class UNREALCHALLENGE1_API UHUDComponent : public UUserWidget
{
	GENERATED_BODY()
	
public:
	void NativeConstruct() override;

	void SetStone(float CurrentStone, float MaxStone);

	void SetWood(float CurrentWood, float MaxWood);

	UPROPERTY(EditAnywhere, meta = (BindWidget));
	class UProgressBar* StoneBar;

	UPROPERTY(EditAnywhere, meta = (BindWidget));
	class UProgressBar* WoodBar;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* maxWood;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* maxStone;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* currentWood;

	UPROPERTY(BlueprintReadOnly, meta = (BindWidget))
	class UTextBlock* currentStone;

private:
	void UpdateProgressBar(UProgressBar* ProgressBar, float Current, float Max);
	void UpdateText(UTextBlock* TextBlock, float Value);
};
