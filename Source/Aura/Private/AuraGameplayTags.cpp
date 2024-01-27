// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	//Primary
	GameplayTags.Attributes_Primary_Strength = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Strength"),
		FString("Increase physical damage")
		);
	GameplayTags.Attributes_Primary_Intelligence = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Primary.Intelligence"),
		FString("Increase Magical damage")
		);
	GameplayTags.Attributes_Primary_Dexterity = UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Primary.Dexterity"),
			FString("Increase Ranged damage")
			);
	GameplayTags.Attributes_Primary_Agility = UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Primary.Agility"),
			FString("Increase AttackSpeed damage")
			);
	GameplayTags.Attributes_Primary_Vitality = UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Primary.Vitality"),
			FString("Increase Survivability damage")
			);
	GameplayTags.Attributes_Primary_Luck = UGameplayTagsManager::Get().AddNativeGameplayTag(
			FName("Attributes.Primary.Luck"),
			FString("Increase critical hit chance")
			);
	
	//Secondary
	GameplayTags.Attributes_Secondary_MaxHealth = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MaxHealth"),
		FString("Max amount of damage to take")
		);
	GameplayTags.Attributes_Secondary_MaxMana = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MaxMana"),
		FString("Increase max mana pool")
		);
	GameplayTags.Attributes_Secondary_Attack = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Attack"),
		FString("Increase physical damage")
		);
	GameplayTags.Attributes_Secondary_MAttack = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MAttack"),
		FString("Increase Magical damage")
		);
	GameplayTags.Attributes_Secondary_Defence = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Defence"),
		FString("Reduce physical damage taken.")
		);
	GameplayTags.Attributes_Secondary_MDefence = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MDefence"),
		FString("Reduce Magical damage taken.")
		);
	GameplayTags.Attributes_Secondary_Flee = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Flee"),
		FString("Reduce critical chance to self.")
		);
	GameplayTags.Attributes_Secondary_Crit = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.Crit"),
		FString("Reduce Magical damage taken.")
		);
	GameplayTags.Attributes_Secondary_HPRegen = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.HPRegen"),
		FString("Reduce Magical damage taken.")
		);
	GameplayTags.Attributes_Secondary_MPRegen = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("Attributes.Secondary.MPRegen"),
		FString("Reduce Magical damage taken.")
		);
	
}
