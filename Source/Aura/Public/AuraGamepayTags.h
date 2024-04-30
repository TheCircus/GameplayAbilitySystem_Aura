// Copyright JonBoy

#pragma once

#include "CoreMinimal.h"
#include "GameplayTagContainer.h"

/**
 * AuraGameplayTags is a singleton containing native gameplay tags
 */

struct FAuraGameplayTags
{
public:
    static FAuraGameplayTags& Get() { return GameplayTags;}
    static void InitializeNativeGameplayTags();

 FGameplayTag Attributes_Secondary_Armor;
protected:

private:
    static FAuraGameplayTags GameplayTags;
 
};
