// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "CameraMovement.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UNREALCHALLENGE1_API UCameraMovement : public UActorComponent
{
	GENERATED_BODY()

public:

	UCameraMovement();

protected:

	virtual void BeginPlay() override;

public:

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void MoveActorX(float axisValue);
	void MoveActorY(float axisValue);
	void MoveActorZ(float axisValue);

	UPROPERTY(EditAnywhere)
	APawn* CameraPawn;

	UPROPERTY(EditAnywhere)
	float SPEED_MULTIPLIER = 20.0f;

	float xMoveSpeed = 0.0f;
	float yMoveSpeed = 0.0f;
	float zMoveSpeed = 0.0f;

	const FName MOVE_X_AXIS_NAME = FName("INPUT_X");
	const FName MOVE_Y_AXIS_NAME = FName("INPUT_Y");
	const FName MOVE_Z_AXIS_NAME = FName("INPUT_Z");

private:

	void MoveCamera(float DeltaTime);
};
