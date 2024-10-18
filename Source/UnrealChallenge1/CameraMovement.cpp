
#include "CameraMovement.h"

// Sets default values for this component's properties
UCameraMovement::UCameraMovement()
{
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UCameraMovement::BeginPlay()
{

	Super::BeginPlay();
	this->CameraPawn->InputComponent->BindAxis(MOVE_X_AXIS_NAME, this, &UCameraMovement::MoveActorX);
	this->CameraPawn->InputComponent->BindAxis(MOVE_Y_AXIS_NAME, this, &UCameraMovement::MoveActorY);
	this->CameraPawn->InputComponent->BindAxis(MOVE_Z_AXIS_NAME, this, &UCameraMovement::MoveActorZ);
	
}


// Called every frame
void UCameraMovement::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (0 != this->xMoveSpeed || 0 != this->yMoveSpeed || 0 != this->zMoveSpeed)
	{
		FVector location = this->CameraPawn->GetActorLocation();
		location.X += this->xMoveSpeed * SPEED_MULTIPLIER * DeltaTime;
		location.Y += this->yMoveSpeed * SPEED_MULTIPLIER * DeltaTime;
		location.Z += this->zMoveSpeed * SPEED_MULTIPLIER * DeltaTime;
		this->CameraPawn->SetActorLocation(location);

		this->xMoveSpeed = 0;  
		this->yMoveSpeed = 0;  
		this->zMoveSpeed = 0;
	}
// ...
}

void UCameraMovement::MoveActorX(float axisValue)
{
	if (axisValue != 0) {
		this->xMoveSpeed = FMath::Clamp(axisValue, -1.0f, 1.0f);
	}
}

void UCameraMovement::MoveActorY(float axisValue)
{
	if (axisValue != 0) {
		this->yMoveSpeed = FMath::Clamp(axisValue, -1.0f, 1.0f);
	}
}

void UCameraMovement::MoveActorZ(float axisValue)
{
	if (axisValue != 0) {
		this->zMoveSpeed = FMath::Clamp(axisValue, -1.0f, 1.0f);
	}
}

