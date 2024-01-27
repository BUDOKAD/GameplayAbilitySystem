// Fill out your copyright notice in the Description page of Project Settings.


#include "AuraGameplayTags.h"
#include "GameplayTagsManager.h"

FAuraGameplayTags FAuraGameplayTags::GameplayTags;

void FAuraGameplayTags::InitializeNativeGameplayTags()
{
	GameplayTags.Attributes_Secondary_Attack = UGameplayTagsManager::Get().AddNativeGameplayTag(FName("Attributs.Secondary.Attack"),FString("Increase hit damage"));
}
