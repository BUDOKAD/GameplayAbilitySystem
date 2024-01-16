// Copyright Druid Mechanics


#include "Player/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);
	CursorTrace();
	
}
void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());
	 
	 /**
	  * Line trace from cursor. there are several scenarios:
	  * A. LastActor is null && ThisAcor is null
	  *		- Do nothing.
	  *	B. LastActor is null && ThisActor is valid
	  *		-Highlight ThisActor
	  * C. LastActor is valid && ThisActor is null
	  *		-UnHighLight lastActor
	  *	D. Both actors are valid but LastActor != ThisActor
	  *		-UnHighLight LastActor, and HighLight ThisActor
	  *	E. Both actors are valid, and are the same actor
	  *		do nothing
	  */
	 if(LastActor == nullptr)
	 {
		 if (ThisActor != nullptr)
		 {
			 // Case B
		 	ThisActor->HighlightActor();
		 }
		 else
		 {
			 // Both are null, A scenario. Do Nothing
		 }
	 	
	 }
	 else // Last Actor is Valid
	 {
		 if (ThisActor == nullptr)
		 {
			 // C scenario
		 	LastActor->UnHighlightActor();
		 }
		 else
		 {
			 //Both are valid
			 if (LastActor!=ThisActor)
			 {
				// D scenario
			 	LastActor->UnHighlightActor();
			 	ThisActor->HighlightActor();
			 }
			 else
			 {
				 // E scenario. Do nothing.
			 }
		 }
	 }
}
void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	if (Subsystem)
	{
		Subsystem->AddMappingContext(AuraContext, 0);
	}
	
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

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}


void AAuraPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
