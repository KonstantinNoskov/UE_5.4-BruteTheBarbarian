#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "EnemyCharacter.generated.h"

UCLASS()
class BRUTE_API AEnemyCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:

	AEnemyCharacter(const FObjectInitializer& ObjectInitializer);

protected:

	virtual void BeginPlay() override;
	
};
