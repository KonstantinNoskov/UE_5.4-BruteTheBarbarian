#include "Game/Controllers/BasePlayerController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Characters/Movement/PlayerMovementComponent.h"


ABasePlayerController::ABasePlayerController()
{
	
}

void ABasePlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	AssignMappingContext();
	
}

void ABasePlayerController::AssignMappingContext()
{
	// Mapping context should be set
	check(BruteContext)
	
	UEnhancedInputLocalPlayerSubsystem* InputSubSystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(InputSubSystem)

	// Set Brute's mapping context
	InputSubSystem->AddMappingContext(BruteContext, 0);
}

void ABasePlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// EnhancedInputComponent Valid Check
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ABasePlayerController::Move);
	EnhancedInputComponent->BindAction(LookAction, ETriggerEvent::Triggered, this, &ABasePlayerController::Look);
	EnhancedInputComponent->BindAction(WalkAction, ETriggerEvent::Started, this, &ABasePlayerController::Walk);
	//EnhancedInputComponent->BindAction(WalkAction, ETriggerEvent::Completed, this, &ABasePlayerController::Walk);
	EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Started, this, &ABasePlayerController::Sprint);
	EnhancedInputComponent->BindAction(SprintAction, ETriggerEvent::Completed, this, &ABasePlayerController::Sprint);
}

void ABasePlayerController::Move(const FInputActionValue& InputActionValue)
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
void ABasePlayerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookAxisVector = InputActionValue.Get<FVector2D>();

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddControllerPitchInput(LookAxisVector.Y);
		ControlledPawn->AddControllerYawInput(LookAxisVector.X);
	}
}

void ABasePlayerController::Walk(const FInputActionValue& InputActionValue)
{
	//const bool bWantsToWalk = InputActionValue.Get<bool>();
	
	bWantsToWalk = !bWantsToWalk;
	if (bWantsToWalk)
	{
		OnMovementPressedDelegate.Broadcast(ECustomMovementMode::Walk);	
	}
	else
	{
		OnMovementPressedDelegate.Broadcast(ECustomMovementMode::Jog);	
	}
}

void ABasePlayerController::Sprint(const FInputActionValue& InputActionValue)
{
	const bool bWantsToSprint = InputActionValue.Get<bool>();
	
	if (bWantsToSprint)
	{
		OnMovementPressedDelegate.Broadcast(ECustomMovementMode::Sprint);	
	}
	else
	{
		OnMovementPressedDelegate.Broadcast(ECustomMovementMode::Jog);
	}
}


