#include "Characters/Movement/PlayerMovementComponent.h"

#include "Game/Controllers/BasePlayerController.h"
#include "Kismet/GameplayStatics.h"

UPlayerMovementComponent::UPlayerMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	InitialGroundSpeed = MaxWalkSpeed;
	
}

void UPlayerMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	BindDependencies();
	
}

void UPlayerMovementComponent::BindDependencies()
{
	
	// Player Controller Valid Check
	BasePlayerController = Cast<ABasePlayerController>(UGameplayStatics::GetPlayerController(this, 0));
	if (IsValid(BasePlayerController))
	{
		BasePlayerController->OnMovementPressedDelegate.AddDynamic(this, &UPlayerMovementComponent::HandleCustomMovement);
	}
}

void UPlayerMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


void UPlayerMovementComponent::HandleCustomMovement(const ECustomMovementMode& DesiredCustomMovementMode)
{
	switch (DesiredCustomMovementMode)
	{
		case Walk :
			CurrentCustomMovementMode = Walk;
			MaxWalkSpeed = WalkMaxWalkSpeed;
			UE_LOG(LogClass, Warning, TEXT("[%hs]: WantsToWalk [%hd]"), __FUNCTION__, bWantsToWalk)
			break;

		case Sprint :
			CurrentCustomMovementMode = Sprint;
			MaxWalkSpeed = SprintMaxWalkSpeed;
			UE_LOG(LogClass, Warning, TEXT("[%hs]: WantsToSprint [%hd]"), __FUNCTION__, bWantsToSprint)
			break;

		default:
			CurrentCustomMovementMode = Jog;
			MaxWalkSpeed = InitialGroundSpeed;
			UE_LOG(LogClass, Warning, TEXT("[%hs]: WantsToJog"), __FUNCTION__)
	}
	
	//bWantsToWalk ? MaxWalkSpeed = WalkMaxWalkSpeed : MaxWalkSpeed = InitialGroundSpeed;
}

