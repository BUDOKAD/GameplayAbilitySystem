// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "UI/WidgetController/OverlayWidgetController.h"

#include "AuraEnemy.generated.h"

class UWidgetComponent;
/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase, public IEnemyInterface
{
	GENERATED_BODY()
public:
	AAuraEnemy();

	/** Enemy Interface */
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	/** emd Enemy Interface */
	/** Combat interface */
	virtual int32 GetPlayerLevel() override;
	/** End Combat interface */

	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangeSignature OnHealthChanged;
	UPROPERTY(BlueprintAssignable)
	FOnAttributeChangeSignature OnMaxHealthChanged;

protected:
	virtual void BeginPlay() override;
	virtual void InitAbilityActorInfo() override;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Character Class Defaults")
	int32 Level = 1;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> HealthBar;
	
};
