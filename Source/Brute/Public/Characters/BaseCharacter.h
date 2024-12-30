#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"

UCLASS()
class BRUTE_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	ABaseCharacter();

	virtual void Tick(float DeltaTime) override;

protected:
	
	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> CharacterMesh;
	
};
