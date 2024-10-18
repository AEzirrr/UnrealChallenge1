// WorkerComponent.cpp

#include "WorkerComponent.h"
#include "Engine/StaticMeshActor.h"


// Sets default values for this component's properties
UWorkerComponent::UWorkerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	LerpSpeed = 0.5f;
	PauseDuration = 5.0f;
	CurrentAlpha = 0.0f;
	bIsPaused = false;

	StartMeshActor = nullptr; // No default, assign via Editor
	EndMeshActor = nullptr;   // No default, assign via Editor
	isWorkerActive = false;    // Default to true, you can modify it in the editor or via code
}


// Called when the game starts
void UWorkerComponent::BeginPlay()
{
	Super::BeginPlay();

	if (StartMeshActor && EndMeshActor)
	{
		StartPoint = StartMeshActor->GetActorLocation();
		EndPoint = EndMeshActor->GetActorLocation();
	}

	// Start movement if the worker is active
	if (isWorkerActive)
	{
		MoveToNextPoint();
	}
}


// Called every frame
void UWorkerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// Check if the worker is active and not paused before moving
	if (isWorkerActive && !bIsPaused)
	{
		CurrentAlpha += LerpSpeed * DeltaTime;
		if (CurrentAlpha >= 1.0f)
		{
			StopMovement();
		}
		else
		{
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

// Start movement if the worker is active
void UWorkerComponent::MoveToNextPoint()
{
	if (isWorkerActive)
	{
		bIsPaused = false;
	}
}
