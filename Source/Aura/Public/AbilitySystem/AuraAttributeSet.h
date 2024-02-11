// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "AuraAttributeSet.generated.h"
#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)



USTRUCT()
struct FEffectProperties
{
	GENERATED_BODY()

	FEffectProperties(){}

	FGameplayEffectContextHandle EffectContextHandle;

	UPROPERTY()
	UAbilitySystemComponent* SourceASC = nullptr;

	UPROPERTY()
	AActor* SourceAvatarActor = nullptr;

	UPROPERTY()
	AController* SourceController = nullptr;

	UPROPERTY()
	ACharacter* SourceCharacter = nullptr;

	UPROPERTY()
	UAbilitySystemComponent* TargetASC = nullptr;

	UPROPERTY()
	AActor* TargetAvatarActor = nullptr;

	UPROPERTY()
	AController* TargetController = nullptr;

	UPROPERTY()
	ACharacter* TargetCharacter = nullptr;
};
// typedef is specific to the FGameplayAttribute() signature, but TstaticFuncPtr is generic to any signature chosen
// typedef TBaseStaticDelegateInstance<FGameplayAttribute(),FDefaultDelegateUserPolicy>::FFuncPtr FAttributeFuncPointer;
template<class  T>
using TStaticFuncPointer = typename TBaseStaticDelegateInstance<T, FDefaultDelegateUserPolicy>::FFuncPtr;

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()
public:
	UAuraAttributeSet();
	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	TMap<FGameplayTag, TStaticFuncPointer<FGameplayAttribute()>> TagsToAttributes;

	
	/*
	 * Primary Attributes
	 */
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Strength, Category = "Primary Attributes")
	FGameplayAttributeData Strength;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Strength);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Intelligence, Category = "Primary Attributes")
	FGameplayAttributeData Intelligence ;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Intelligence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Dexterity, Category = "Primary Attributes")
	FGameplayAttributeData Dexterity;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Dexterity);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Agility, Category = "Primary Attributes")
	FGameplayAttributeData Agility;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Agility);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Vitality, Category = "Primary Attributes")
	FGameplayAttributeData Vitality;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Vitality);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Luck, Category = "Primary Attributes")
	FGameplayAttributeData Luck;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Luck);

	/**
	 * Secondary Attributes
	 */

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Attack, Category = "Secondary Attributes")
	FGameplayAttributeData Attack;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Attack);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MAttack, Category = "Secondary Attributes")
	FGameplayAttributeData MAttack ;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MAttack);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Defence, Category = "Secondary Attributes")
	FGameplayAttributeData Defence;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Defence);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MDefence, Category = "Secondary Attributes")
	FGameplayAttributeData MDefence;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MDefence);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Flee, Category = "Secondary Attributes")
	FGameplayAttributeData Flee;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Flee);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Crit, Category = "Secondary Attributes")
	FGameplayAttributeData Crit;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Crit);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_HPRegen, Category = "Secondary Attributes")
	FGameplayAttributeData HPRegen;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, HPRegen);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MPRegen, Category = "Secondary Attributes")
	FGameplayAttributeData MPRegen;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MPRegen);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "Secondary Attributes")
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxHealth);

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "Secondary Attributes")
	FGameplayAttributeData MaxMana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, MaxMana);
	
	/**
	 * Vital Attributes
	 */
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "Vital Attributes")
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Health);
	
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "Vital Attributes")
	FGameplayAttributeData Mana;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, Mana);

	/**
	 * Meta Attributes 
	 */

	UPROPERTY(BlueprintReadOnly, Category="Meta Attributes")
	FGameplayAttributeData IncomingDamage;
	ATTRIBUTE_ACCESSORS(UAuraAttributeSet, IncomingDamage);

	

	/*
	 * Primary Attributes
	 */
	
	
	UFUNCTION()
	void OnRep_Strength(const FGameplayAttributeData& OldStrength) const;
	UFUNCTION()
	void OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const;
	UFUNCTION()
	void OnRep_Dexterity(const FGameplayAttributeData& OldDexterity) const;
	UFUNCTION()
	void OnRep_Agility(const FGameplayAttributeData& OldAgility) const;
	UFUNCTION()
	void OnRep_Vitality(const FGameplayAttributeData& OldVitality) const;
	UFUNCTION()
	void OnRep_Luck(const FGameplayAttributeData& OldLuck) const;

	/*
	 * Secondary Attributes
	 */
	
	
	UFUNCTION()
	void OnRep_Attack(const FGameplayAttributeData& OldAttack) const;
	UFUNCTION()
	void OnRep_MAttack(const FGameplayAttributeData& OldMAttack) const;
	UFUNCTION()
	void OnRep_Defence(const FGameplayAttributeData& OldDefence) const;
	UFUNCTION()
	void OnRep_MDefence(const FGameplayAttributeData& OldMDefence) const;
	UFUNCTION()
	void OnRep_Flee(const FGameplayAttributeData& OldFlee) const;
	UFUNCTION()
	void OnRep_Crit(const FGameplayAttributeData& OldCrit) const;
	UFUNCTION()
	void OnRep_HPRegen(const FGameplayAttributeData& OldHPRegen) const;
	UFUNCTION()
	void OnRep_MPRegen(const FGameplayAttributeData& OldMPRegen) const;
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
	
	/*
	 *Vital Attribute 
	 */
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	

private:

	void SetEffectProperties(const FGameplayEffectModCallbackData& Data, FEffectProperties& Props) const;
	void ShowFloatingText(const FEffectProperties& Props, float Damage)const;
};