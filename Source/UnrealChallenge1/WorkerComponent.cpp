// Fill out your copyright notice in the Description page of Project Settings.


#include "WorkerComponent.h"

// Sets default values for this component's properties
UWorkerComponent::UWorkerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	LerpSpeed = 0.5f;
	PauseDuration = 5.0f;
	CurrentAlpha = 0.0f;
	bIsPaused = false;

	StartMeshActor = nullptr; // No default, assign via Editor
	EndMeshActor = nullptr;   // No default, assign via Editor
}


// Called when the game starts
void UWorkerComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	// Start the movement initially
	MoveToNextPoint();
}


// Called every frame
void UWorkerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if (!bIsPaused)
	{
		CurrentAlpha += LerpSpeed * DeltaTime;
		if (CurrentAlpha >= 1.0f)
		{
			StopMovement();
		}
		else
		{
			// Lerp between StartPoint and EndPoint
			FVector NewPosition = FMath::Lerp(StartPoint, EndPoint, CurrentAlpha);
			Worker->SetActorLocation(NewPosition);


		}
	}
}

// Stop the movement and start the pause timer
void UWorkerComponent::StopMovement()
{
	bIsPaused = true;

	// Swap StartPoint and EndPoint
	FVector TempPoint = StartPoint;
	StartPoint = EndPoint;
	EndPoint = TempPoint;

	CurrentAlpha = 0.0f;

	// Set timer for pause duration
	GetWorld()->GetTimerManager().SetTimer(PauseTimerHandle, this, &UWorkerComponent::ResumeMovement, PauseDuration, false);
}

// Resume movement after pause
void UWorkerComponent::ResumeMovement()
{
	bIsPaused = false;
}

// Start movement
void UWorkerComponent::MoveToNextPoint()
{
	bIsPaused = false;
}
