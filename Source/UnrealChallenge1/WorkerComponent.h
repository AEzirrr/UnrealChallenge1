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
    bool isWorkerActive; 

    UPROPERTY(EditAnywhere)
    AStaticMeshActor* StartMeshActor;

    UPROPERTY(EditAnywhere)
    AStaticMeshActor* EndMeshActor;

    UPROPERTY(EditAnywhere)
    FVector StartPoint;

    UPROPERTY(EditAnywhere)
    FVector EndPoint;

    float LerpSpeed;

    FTimerHandle PauseTimerHandle;

    float PauseDuration;

    float CurrentAlpha;

    bool bIsPaused;

    void MoveToNextPoint();

    void ResumeMovement();

    void StopMovement();

    AActor* Worker = GetOwner();

public:

    UFUNCTION(BlueprintCallable, Category = "Worker Component")
    void ActivateWorker();
};
