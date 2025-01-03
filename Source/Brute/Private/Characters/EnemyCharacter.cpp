#include "Characters/EnemyCharacter.h"

AEnemyCharacter::AEnemyCharacter(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;
}

void AEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
}
