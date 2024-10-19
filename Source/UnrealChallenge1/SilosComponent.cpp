// Fill out your copyright notice in the Description page of Project Settings.


#include "SilosComponent.h"

// Sets default values for this component's properties
USilosComponent::USilosComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void USilosComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	if (!SiloTrigger1)
	{
		UE_LOG(LogTemp, Error, TEXT("Silo Trigger is not Set!"));
		return;
	}
	
}


// Called every frame
void USilosComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Get the player pawn
	APawn* thePlayer = this->GetWorld()->GetFirstPlayerController()->GetPawn();

	// Check if the player exists
	if (thePlayer)
	{
		if (this->SiloTrigger1 && this->SiloTrigger1->IsOverlappingActor(thePlayer))
		{
			ActivateSilo();
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Player does not exist."));
	}

}

void USilosComponent::ActivateSilo()
{
	UE_LOG(LogTemp, Warning, TEXT("Silo Activated!"));
	/*

		Put logic for when activated, GetMaxNumWood / GetMaxNumStone and add value

	*/
}

