// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
    check(AuraContext)

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext, 0);


	
	//Cursor Settings
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;
	
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	UEnhancedInputComponent*EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	
	EnhancedInputComponent ->BindAction(MoveAction, ETriggerEvent::Triggered,this, &AAuraPlayerController::Move);
	

	
}
// Movment Function
void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2d InputActionVector = InputActionValue.Get<FVector2d>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw,0.f);


	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxes(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxes(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		 ControlledPawn->AddMovementInput(ForwardDirection,InputActionVector.Y);
		ControlledPawn->AddMovementInput(RightDirection,InputActionVector.X);
	}
}
