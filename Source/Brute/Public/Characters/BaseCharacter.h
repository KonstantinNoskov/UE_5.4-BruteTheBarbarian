#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseCharacter.generated.h"


UCLASS(Abstract)
class BRUTE_API ABaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	ABaseCharacter(const FObjectInitializer& ObjectInitializer);

	virtual void Tick(float DeltaTime) override;

protected:
	
	virtual void BeginPlay() override;


protected:
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USkeletalMeshComponent> CharacterMesh;

	UPROPERTY(EditAnywhere, Category = "Combat")
	TObjectPtr<USkeletalMeshComponent> WeaponMesh;
	
	
};
