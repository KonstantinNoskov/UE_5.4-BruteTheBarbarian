#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "BasePlayerController.generated.h"


enum ECustomMovementMode : uint8;
struct FInputActionValue;
class UInputAction;
class UInputMappingContext;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnMovementPressedSignature, const ECustomMovementMode&, DisCustomMovementMode);

UCLASS()
class BRUTE_API ABasePlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	friend class UPlayerMovementComponent;
	
	ABasePlayerController();
	void AssignMappingContext();
	
protected:
	
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;

	

private:
	
	void Move(const FInputActionValue& InputActionValue);
	void Look(const FInputActionValue& InputActionValue);
	void Walk(const FInputActionValue& InputActionValue);
	void Sprint(const FInputActionValue& InputActionValue);
	
	UPROPERTY(EditAnywhere, Category = "input")
	TObjectPtr<UInputMappingContext> BruteContext;
	
	UPROPERTY(EditAnywhere, Category = "input")
	TObjectPtr<UInputAction> LookAction;

	UPROPERTY(EditAnywhere, Category = "input")
	TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "input")
	TObjectPtr<UInputAction> WalkAction;


	TMap<FString, TObjectPtr<UInputAction>> InputActionsMap;
	bool bWantsToWalk = false;
	
	UPROPERTY(EditAnywhere, Category = "input")
	TObjectPtr<UInputAction> SprintAction;

	 ECustomMovementMode CustomMovementMode;
	
public:
	
	FOnMovementPressedSignature OnMovementPressedDelegate; 
};
