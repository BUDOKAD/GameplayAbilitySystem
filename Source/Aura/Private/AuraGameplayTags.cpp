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


	////////////////////Input tags///////////////////////

	GameplayTags.InputTag_LMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.LMB"),
		FString("Left Mouse Button")
		);
	GameplayTags.InputTag_RMB = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.RMB"),
		FString("Right Mouse Button")
		);
	GameplayTags.InputTag_1 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.1"),
		FString(" 1 numeric button")
		);
	GameplayTags.InputTag_2 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.2"),
		FString("2 numeric button")
		);
	GameplayTags.InputTag_3 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.3"),
		FString("3 numeric button")
		);
	GameplayTags.InputTag_4 = UGameplayTagsManager::Get().AddNativeGameplayTag(
		FName("InputTag.4"),
		FString("4 numeric button")
		);
	GameplayTags.InputTag_5 = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("InputTag.5"),
	FString("5 numeric button")
	);


	GameplayTags.Damage = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Damage"),
	FString("Damage Recived")
	);
	GameplayTags.Healing = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Healing"),
	FString("Healing Recived")
	);
	GameplayTags.Effects_HitReact = UGameplayTagsManager::Get().AddNativeGameplayTag(
	FName("Effects.HitReact"),
	FString("HitReact")
	);
}
