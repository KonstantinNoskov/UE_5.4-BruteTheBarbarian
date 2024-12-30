#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"


struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

UCLASS()
class BRUTE_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	
	ABasePlayerController();
	void AssignMappingContext();

protected:
	
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

private:

	void Move(const FInputActionValue& InputActionValue);
	void Look(const FInputActionValue& InputActionValue);
	
	UPROPERTY(EditAnywhere, Category = "input")
	TObjectPtr<UInputMappingContext> BruteContext;

	UPROPERTY(EditAnywhere, Category = "input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "input")
	TObjectPtr<UInputAction> LookAction;
	
};
