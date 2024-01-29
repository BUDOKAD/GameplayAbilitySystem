// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "GameplayTagContainer.h"
#include "CoreMinimal.h"

/**
 * 
 */
struct FAuraGameplayTags
{
public:
	static const FAuraGameplayTags get(){return GameplayTags;}
	static void  InitializeNativeGameplayTags();


	FGameplayTag Attributes_Primary_Strength;
	FGameplayTag Attributes_Primary_Intelligence;
	FGameplayTag Attributes_Primary_Dexterity;
	FGameplayTag Attributes_Primary_Agility;
	FGameplayTag Attributes_Primary_Vitality;
	FGameplayTag Attributes_Primary_Luck;
	
	FGameplayTag Attributes_Secondary_MaxHealth;
	FGameplayTag Attributes_Secondary_MaxMana;
	FGameplayTag Attributes_Secondary_Attack;
	FGameplayTag Attributes_Secondary_MAttack;
	FGameplayTag Attributes_Secondary_Defence;
	FGameplayTag Attributes_Secondary_MDefence;
	FGameplayTag Attributes_Secondary_Flee;
	FGameplayTag Attributes_Secondary_Crit;
	FGameplayTag Attributes_Secondary_HPRegen;
	FGameplayTag Attributes_Secondary_MPRegen;

	FGameplayTag InputTag_LMB;
	FGameplayTag InputTag_RMB;
	FGameplayTag InputTag_1;
	FGameplayTag InputTag_2;
	FGameplayTag InputTag_3;
	FGameplayTag InputTag_4;
	FGameplayTag InputTag_5;
	
	
private:
	static FAuraGameplayTags GameplayTags;
};