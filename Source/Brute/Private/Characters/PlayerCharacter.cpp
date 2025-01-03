#include "Characters/PlayerCharacter.h"

#include "Camera/CameraComponent.h"
#include "Characters/Movement/PlayerMovementComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

APlayerCharacter::APlayerCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer.SetDefaultSubobjectClass<UPlayerMovementComponent>(ACharacter::CharacterMovementComponentName))
{

#pragma region CAPSULE

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

#pragma endregion

#pragma region MESH

	GetMesh()->SetupAttachment(GetRootComponent());
	GetMesh()->AddLocalRotation(FRotator(0.f,-90.f,0.f));

#pragma endregion
#pragma region CAMERA

	SpringArm = CreateDefaultSubobject<USpringArmComponent>("SpringArm");
	SpringArm->SetupAttachment(GetRootComponent());
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->bInheritPitch = true;
	SpringArm->bInheritYaw = true;
	SpringArm->bInheritRoll = true;

	Camera = CreateDefaultSubobject<UCameraComponent>("Camera");
	Camera->SetupAttachment(SpringArm);

#pragma endregion
#pragma region CHARACTER MOVEMENT

	// Set Custom Movement Component
	PlayerMovementComponent = Cast<UPlayerMovementComponent>(GetCharacterMovement());
	PlayerMovementComponent->bOrientRotationToMovement = true;
	PlayerMovementComponent->RotationRate - FRotator(0.f, 400.f, 0.f);

#pragma endregion
	
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


