

#pragma once

#include "CoreMinimal.h"
#include "PlayerCharacter.h"
#include "BruteCharacter.generated.h"

UCLASS()
class BRUTE_API ABruteCharacter : public APlayerCharacter
{
	GENERATED_BODY()

public:
	ABruteCharacter();

protected:
	virtual void BeginPlay() override;


	

};
