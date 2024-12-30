#include "Brute/Public/Characters/BaseCharacter.h"

#include "Components/CapsuleComponent.h"


ABaseCharacter::ABaseCharacter()
{
	PrimaryActorTick.bCanEverTick = true;
	
	GetMesh()->SetupAttachment(GetRootComponent());
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
