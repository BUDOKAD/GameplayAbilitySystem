// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AuraEffectActor.generated.h"

class UAuraAbilitySystemComponent;
class UGameplayEffect;

UENUM(BlueprintType)
enum class EEffectApplicationPolicy
{
	ApplyOnOverlap,
	ApplyOnEndOverlap,
	DoNotApply
};

UENUM(BlueprintType)
enum class EEffectRemovalPolicy
{
	RemoveOnEndOverlap,
	DoNotRemove
};
 


UCLASS()
class AURA_API AAuraEffectActor : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AAuraEffectActor();
	
	
protected:

	virtual void BeginPlay() override;

	UFUNCTION(BlueprintCallable)
	void ApplyEffectsToTarget(AActor* TargetActor, TSubclassOf<UGameplayEffect>GameplayEffectClass);

	UFUNCTION(BlueprintCallable)
	void OnOverlap(AActor* TargetActor);

	UFUNCTION(BlueprintCallable)
	void OnEndOverlap(AActor* TargetActor);


	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Applied Effects");
	bool bDestroyOnEffectRemoval = false;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Applied Effects");
	TSubclassOf<UGameplayEffect> InstantGameplayEffectClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Applied Effects");
	EEffectApplicationPolicy InstantEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Applied Effects");
	TSubclassOf<UGameplayEffect> DurationGamePlayEffectClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Applied Effects");
	EEffectApplicationPolicy DurationEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Applied Effects");
	TSubclassOf<UGameplayEffect> InfiniteGamePlayEffectClass;
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Applied Effects");
	EEffectApplicationPolicy InfiniteEffectApplicationPolicy = EEffectApplicationPolicy::DoNotApply;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Applied Effects");
	EEffectRemovalPolicy InfiniteEffectRemovalPolicy = EEffectRemovalPolicy::RemoveOnEndOverlap;

	TMap<FActiveGameplayEffectHandle, UAbilitySystemComponent*> ActiveEffectHandles;
	
	
};
