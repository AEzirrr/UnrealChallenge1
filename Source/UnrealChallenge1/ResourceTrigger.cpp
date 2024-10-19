#include "ResourceTrigger.h"
#include "WorkerComponent.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"
#include "Engine/TriggerVolume.h"

UResourceTrigger::UResourceTrigger()
{
    PrimaryComponentTick.bCanEverTick = true;
}

void UResourceTrigger::BeginPlay()
{
    Super::BeginPlay();

    if (!baseTrigger1)
    {
        UE_LOG(LogTemp, Error, TEXT("BaseTrigger1 is not set!"));
        return;
    }

    AActor* Owner = GetOwner();
    APawn* thePlayer = this->GetWorld()->GetFirstPlayerController()->GetPawn();
    //UPlayerResourceComponent* playerReso = ()->SpawnActor<UPlayerResourceComponent>();
    //UPlayerResourceComponent* playerReso = Cast<UPlayerResourceComponent>(()->SpawnActor(UPlayerResourceComponent::StaticClass())));
}


TArray<AActor*> CurrentlyOverlappingActors;

// Called every frame
void UResourceTrigger::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
    Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

    if (!baseTrigger1)
    {
        return;
    }

    TArray<AActor*> OverlappingActors;
    baseTrigger1->GetOverlappingActors(OverlappingActors);

    for (AActor* Actor : OverlappingActors)
    {
        if (!CurrentlyOverlappingActors.Contains(Actor))
        {
            UWorkerComponent* Worker = Actor->FindComponentByClass<UWorkerComponent>();

            if (Worker)
            {
                if (Worker->Woodworker == 1) {
                    //add wood
                    UE_LOG(LogTemp, Warning, TEXT("%s is getting wood"), *Actor->GetName())
                    UPlayerResourceComponent::AddWood(10.f);
                }
                if (Worker->Woodworker == 0)
                {
                    UE_LOG(LogTemp, Warning, TEXT("%s is getting stone"), *Actor->GetName())
                    UPlayerResourceComponent::AddStone(4.f);
                }
            }
            else
            {
                UE_LOG(LogTemp, Warning, TEXT("its null"), *Actor->GetName())
            }
            
            UE_LOG(LogTemp, Warning, TEXT("TRIGGERED by %s"), *Actor->GetName());
            CurrentlyOverlappingActors.Add(Actor);
        }
        
    }

    for (int32 i = CurrentlyOverlappingActors.Num() - 1; i >= 0; i--)
    {
        AActor* TrackedActor = CurrentlyOverlappingActors[i];
        if (!OverlappingActors.Contains(TrackedActor))
        {
            CurrentlyOverlappingActors.RemoveAt(i);
        }
    }
}