#include "WorkerComponent.h"
#include "Engine/StaticMeshActor.h"


UWorkerComponent::UWorkerComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	LerpSpeed = 0.5f;
	PauseDuration = 5.0f;
	CurrentAlpha = 0.0f;
	bIsPaused = false;

	StartMeshActor = nullptr; 
	EndMeshActor = nullptr;  
	isWorkerActive = false;   
}


// Called when the game starts
void UWorkerComponent::BeginPlay()
{
	Super::BeginPlay();


	if (AActor* Owner = GetOwner())
	{

		StartPoint = Owner->GetActorLocation();

		if (EndMeshActor)
		{
			EndPoint = EndMeshActor->GetActorLocation();
		}
	}

	if (isWorkerActive)
	{
		MoveToNextPoint();
	}
}



// Called every frame
void UWorkerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

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

void UWorkerComponent::StopMovement()
{
	bIsPaused = true;

	FVector TempPoint = StartPoint;
	StartPoint = EndPoint;
	EndPoint = TempPoint;

	CurrentAlpha = 0.0f;

	GetWorld()->GetTimerManager().SetTimer(PauseTimerHandle, this, &UWorkerComponent::ResumeMovement, PauseDuration, false);
}

void UWorkerComponent::ResumeMovement()
{
	bIsPaused = false;
}

void UWorkerComponent::MoveToNextPoint()
{
	if (isWorkerActive)
	{
		bIsPaused = false;
	}
}

void UWorkerComponent::ActivateWorker() 
{
	if (isWorkerActive == false) {
		isWorkerActive = true;
		bIsPaused = false;
	}
}
