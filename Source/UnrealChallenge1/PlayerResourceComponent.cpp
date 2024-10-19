// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerResourceComponent.h"


float UPlayerResourceComponent::maxWood = 100;
float UPlayerResourceComponent::maxStone = 100;
float UPlayerResourceComponent::currWood = 100;
float UPlayerResourceComponent::currStone = 0;
int32 UPlayerResourceComponent::activeSilos  = 1;


// Sets default values for this component's properties
UPlayerResourceComponent::UPlayerResourceComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UPlayerResourceComponent::BeginPlay()
{
	Super::BeginPlay();

	currWood = 100;
	currStone = 0;
	// ...
	
}


// Called every frame
void UPlayerResourceComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerResourceComponent::AddWood(float woodToAdd) 
{
	currWood = currWood + woodToAdd;
	UE_LOG(LogTemp, Warning, TEXT("currwood: %f"), currWood);
}

void UPlayerResourceComponent::AddStone(float stoneToAdd)
{
	currStone = currStone + stoneToAdd;
	UE_LOG(LogTemp, Warning, TEXT("currStone: %f"), currStone);
}

