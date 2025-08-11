
#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"

#include "InputActionValue.h"
#include "CharacterTypes.h"
#include "Interfaces/PickupInterface.h"
#include "SlashCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;
class AItem;
class ASoul;
class ATreasure;
class UAnimMontage;
class USlashOverlay;
class UInputMappingContext;
class UInputAction;



UCLASS()
class SLASH_ARPG_LP_UE5_API ASlashCharacter : public ABaseCharacter, public IPickupInterface
{
	GENERATED_BODY()

public:
	ASlashCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void Jump() override;
	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;



	
protected:
	virtual void BeginPlay() override;

	//Callbacks for Input
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);
	void Zoom(const FInputActionValue& Value);
	void Interact(const FInputActionValue& Value);
	void DodgeRoll(const FInputActionValue& Value);
	bool HasEnoughStamina();
	bool IsOccupied();
	void Arm();
	void Disarm();
	void EquipWeapon(AWeapon* OverlappingWeapon);
	void LeftClick(const FInputActionValue& Value);

	virtual void Die() override;

	virtual void GetHit_Implementation(const FVector& ImpactPoint, AActor* Hitter) override;
	virtual void SetOverlappingItem(AItem* Item) override;
	virtual void AddSouls(ASoul* Soul) override;
	virtual void AddGold(ATreasure* Treasure) override;
	virtual void Attack() override;

	//Play montage functions
	
	virtual void AttackEnd() override;
	virtual void DodgingEnd() override;
	virtual bool CanAttack() override;

	void PlayWeaponEquipMontage(const FName SectionName);
	bool CanDisarm();
	bool CanArm();

	UFUNCTION(BlueprintCallable)
	void AttacheWeaponToBack();

	UFUNCTION(BlueprintCallable)
	void AttacheWeaponToHand();

	UFUNCTION(BlueprintCallable)
	void FinishedEquipping();

	UFUNCTION(BlueprintCallable)
	void HitReactEnd();

private:

	ECharacterState CharacterState = ECharacterState::ESC_Unequipped;
	UPROPERTY(BlueprintReadWrite, meta = (AllowPrivateAccess ="true"))
	EActionState ActionState = EActionState::EAS_Unoccupied;

	UPROPERTY()
	USlashOverlay* SlashOverlay;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* ViewCamera;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	UGroomComponent* Hair;

	UPROPERTY(VisibleAnywhere, Category = Hair)
	UGroomComponent* Eyebrows;

	UPROPERTY(VisibleInstanceOnly, Category = Interact)
	AItem* OverlappingItem;

	bool IsUnoccupied();
	void InitializeSlashOverlay();
	void SetHUDHealth();

protected:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputMappingContext* SlashCharacterMappingContext;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* MovementAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* LookAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* JumpAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* InteractAction;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* LeftMousClick;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* DodgeRollAktion;

	//Zoom config
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
	UInputAction* ZoomAction;
	UPROPERTY(EditAnywhere, Category = "Camera Zoom")
	float ZoomSpeed = 50.0f;
	UPROPERTY(EditAnywhere, Category = "Camera Zoom")
	float MinZoom = 150.0f;
	UPROPERTY(EditAnywhere, Category = "Camera Zoom")
	float MaxZoom = 600.0f;

	

public:
	FORCEINLINE ECharacterState GetCharacterState() const { return CharacterState; }
	FORCEINLINE EActionState GetActionState() const { return ActionState; }
};
