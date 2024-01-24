// Fill out your copyright notice in the Description page of Project Settings.


#include "AbilitySystem/AuraAttributeSet.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "GameFramework/Character.h"
#include "GameplayEffectExtension.h"
#include "Net/UnrealNetwork.h"

UAuraAttributeSet::UAuraAttributeSet()
{
	InitHealth(20.f);
	InitMana(10.f);
}
void UAuraAttributeSet::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Attack, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Intelligence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Dexterity, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Agility, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Vitality, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Luck, COND_None, REPNOTIFY_Always);

	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Attack, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MAttack, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Defence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MDefence, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Flee, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Crit, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, HPRegen, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MPRegen, COND_None, REPNOTIFY_Always);

	
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxHealth, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, Mana, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UAuraAttributeSet, MaxMana, COND_None, REPNOTIFY_Always);
}
void UAuraAttributeSet::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	Super::PreAttributeChange(Attribute, NewValue);
	if (Attribute == GetHealthAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxHealth());
	}
	if (Attribute == GetManaAttribute())
	{
		NewValue = FMath::Clamp(NewValue, 0.f, GetMaxMana());
	}
}

void UAuraAttributeSet::SetEffectProperties(const FGameplayEffectModCallbackData& Data,FEffectProperties& Props) const
{
	// Source = causer of the effect, Target = target of the effect (owner of this AS)

	Props.EffectContextHandle = Data.EffectSpec.GetContext();
	Props.SourceASC = Props.EffectContextHandle.GetOriginalInstigatorAbilitySystemComponent();

	if (IsValid(Props.SourceASC) && Props.SourceASC->AbilityActorInfo.IsValid() && Props.SourceASC->AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.SourceAvatarActor = Props.SourceASC->AbilityActorInfo->AvatarActor.Get();
		Props.SourceController = Props.SourceASC->AbilityActorInfo->PlayerController.Get();
		if (Props.SourceController == nullptr && Props.SourceAvatarActor != nullptr)
		{
			if (const APawn* Pawn = Cast<APawn>(Props.SourceAvatarActor))
			{
				Props.SourceController = Pawn->GetController();
			}
		}
		if (Props.SourceController)
		{
			ACharacter* SourceCharacter = Cast<ACharacter>(Props.SourceController->GetPawn());
		}
	}

	if (Data.Target.AbilityActorInfo.IsValid() && Data.Target.AbilityActorInfo->AvatarActor.IsValid())
	{
		Props.TargetAvatarActor = Data.Target.AbilityActorInfo->AvatarActor.Get();
		Props.TargetController = Data.Target.AbilityActorInfo->PlayerController.Get();
		Props.TargetCharacter = Cast<ACharacter>(Props.TargetAvatarActor);
		Props.TargetASC = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Props.TargetAvatarActor);
	}
}

void UAuraAttributeSet::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

	FEffectProperties Props;
	SetEffectProperties(Data, Props);
	if (Data.EvaluatedData.Attribute == GetHealthAttribute())
	{
		SetHealth(FMath::Clamp(GetHealth(),0.f,GetMaxHealth()));
	}
	if (Data.EvaluatedData.Attribute == GetManaAttribute())
	{
		SetMana(FMath::Clamp(GetMana(),0.f,GetMaxMana()));
	}

}

void UAuraAttributeSet::OnRep_Strength(const FGameplayAttributeData& OldStrength) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Strength, OldStrength);
}

void UAuraAttributeSet::OnRep_Intelligence(const FGameplayAttributeData& OldIntelligence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Intelligence, OldIntelligence);
}

void UAuraAttributeSet::OnRep_Dexterity(const FGameplayAttributeData& OldDexterity) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Dexterity, OldDexterity);
}

void UAuraAttributeSet::OnRep_Agility(const FGameplayAttributeData& OldAgility) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Agility, OldAgility);
}

void UAuraAttributeSet::OnRep_Vitality(const FGameplayAttributeData& OldVitality) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Vitality, OldVitality);
}

void UAuraAttributeSet::OnRep_Luck(const FGameplayAttributeData& OldLuck) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Luck, OldLuck);
}

void UAuraAttributeSet::OnRep_Attack(const FGameplayAttributeData& OldAttack) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Attack, OldAttack);
}

void UAuraAttributeSet::OnRep_MAttack(const FGameplayAttributeData& OldMAttack) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MAttack, OldMAttack);
}

void UAuraAttributeSet::OnRep_Defence(const FGameplayAttributeData& OldDefence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Defence, OldDefence);
}

void UAuraAttributeSet::OnRep_MDefence(const FGameplayAttributeData& OldMDefence) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MDefence, OldMDefence);
}

void UAuraAttributeSet::OnRep_Flee(const FGameplayAttributeData& OldFlee) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Flee, OldFlee);
}

void UAuraAttributeSet::OnRep_Crit(const FGameplayAttributeData& OldCrit) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Crit, OldCrit);
}

void UAuraAttributeSet::OnRep_HPRegen(const FGameplayAttributeData& OldHPRegen) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, HPRegen, OldHPRegen);
}

void UAuraAttributeSet::OnRep_MPRegen(const FGameplayAttributeData& OldMPRegen) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MPRegen, OldMPRegen);
}

void UAuraAttributeSet::OnRep_Health(const FGameplayAttributeData& OldHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Health, OldHealth);
}
void UAuraAttributeSet::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxHealth, OldMaxHealth);
}
void UAuraAttributeSet::OnRep_Mana(const FGameplayAttributeData& OldMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, Mana, OldMana);
}
void UAuraAttributeSet::OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UAuraAttributeSet, MaxMana, OldMaxMana);
}


