// WorkerComponent.h

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "WorkerComponent.generated.h"


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UNREALCHALLENGE1_API UWorkerComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    // Sets default values for this component's properties
    UWorkerComponent();

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

    UPROPERTY(EditAnywhere)
    bool isWorkerActive;  // Controls whether the worker is active and can move

    // References to the Static Mesh Actors in the world
    UPROPERTY(EditAnywhere)
    AStaticMeshActor* StartMeshActor;

    UPROPERTY(EditAnywhere)
    AStaticMeshActor* EndMeshActor;

    // Points for the NPC to move between
    UPROPERTY(EditAnywhere)
    FVector StartPoint;

    UPROPERTY(EditAnywhere)
    FVector EndPoint;

    // Lerp speed
    float LerpSpeed;

    // Timer handle for the pause
    FTimerHandle PauseTimerHandle;

    // Time to wait before moving to the next point
    float PauseDuration;

    // Current alpha value for Lerp
    float CurrentAlpha;

    // Boolean to check if the NPC is currently paused
    bool bIsPaused;

    // Function to start the movement
    void MoveToNextPoint();

    // Function called after the pause ends
    void ResumeMovement();

    // Function to stop movement and start timer
    void StopMovement();

    AActor* Worker = GetOwner();
};
