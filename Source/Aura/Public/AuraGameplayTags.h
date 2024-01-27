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

protected:

private:
 static FAuraGameplayTags GameplayTags;
};