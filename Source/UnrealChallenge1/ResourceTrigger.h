#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "PlayerResourceComponent.h"
#include "WorkerComponent.h"
#include "GameFramework/Actor.h"
#include "ResourceTrigger.generated.h"

UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UNREALCHALLENGE1_API UResourceTrigger : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UResourceTrigger();

	UPROPERTY(EditAnywhere)
	ATriggerVolume* baseTrigger1;  // Use UBoxComponent for overlap detection

	//UPROPERTY(EditAnywhere)
	//UPlayerResourceComponent* playerReso;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
};