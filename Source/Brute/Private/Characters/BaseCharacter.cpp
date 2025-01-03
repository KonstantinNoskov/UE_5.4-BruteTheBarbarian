#include "Characters/BaseCharacter.h"

ABaseCharacter::ABaseCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	
{
	PrimaryActorTick.bCanEverTick = true;

	// Mesh
	GetMesh()->SetupAttachment(GetRootComponent());
	GetMesh()->AddLocalRotation(FRotator(0.f,-90.f,0.f));
	
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
	WeaponMesh->SetupAttachment(GetMesh(), FName("SKT_RightHand_Weapon"));
	WeaponMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


