#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "PlayerCharacter.generated.h"

class UPlayerMovementComponent;
class UCameraComponent;
class USpringArmComponent;
class UInputMappingContext;

UCLASS()
class BRUTE_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	
	APlayerCharacter(const FObjectInitializer& ObjectInitializer);

	virtual void Tick(float DeltaTime) override;

protected:
	
	virtual void BeginPlay() override;
	
	// Custom Movement
	TObjectPtr<UPlayerMovementComponent> PlayerMovementComponent;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<USpringArmComponent> SpringArm;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UCameraComponent> Camera;
	
};
