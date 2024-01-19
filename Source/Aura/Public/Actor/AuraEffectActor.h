// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AuraEffectActor.generated.h"

class UGameplayEffect;

UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAuraEffectActor();
	
	
protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void AppliedEffectsToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect>GameplayEffectClass);


	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Applied Effects");
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
	
};
