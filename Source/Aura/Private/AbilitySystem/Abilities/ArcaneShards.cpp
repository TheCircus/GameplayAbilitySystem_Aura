// Copyright JonBoy


#include "AbilitySystem/Abilities/ArcaneShards.h"

FString UArcaneShards::GetDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	if (Level == 1)
	{
		return FString::Printf(TEXT(
			// Title
			"<Title>Arcane Shards</>\n\n"

			// Level
			"<Small>Level: </><Level>%d</>\n"
			// ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			// Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

			//Description
			"<Default>Summon a shard of arcane energy,"
			"causing radial arcane damage of </>"

			// Damage
			"<Damage>%d</><Default> at the shard origin</>"),

			// Values
			Level,
			ManaCost,
			Cooldown,
			ScaledDamage);
	}
	else
	{
		return FString::Printf(TEXT(
			// Title
			"<Title>Arcane Shards</>\n\n"

			// Level
			"<Small>Level: </><Level>%d</>\n"
			// ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			// Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

			// Additional Number of Shards
			"<Default>Summon %d shards of arcane energy, causing radial arcane damage </>"

			// Damage
			"<Damage>%d</><Default> damage at the shard origins.</>"),

			// Values
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level,MaxNumShards),
			ScaledDamage);
	}
}

FString UArcaneShards::GetNextLevelDescription(int32 Level)
{
	const int32 ScaledDamage = Damage.GetValueAtLevel(Level);
	const float ManaCost = FMath::Abs(GetManaCost(Level));
	const float Cooldown = GetCooldown(Level);
	return FString::Printf(TEXT(
			// Title
			"<Title>Next level:</>\n\n"

			// Level
			"<Small>Level: </><Level>%d</>\n"
			// ManaCost
			"<Small>ManaCost: </><ManaCost>%.1f</>\n"
			// Cooldown
			"<Small>Cooldown: </><Cooldown>%.1f</>\n\n"

			// Additional Number of Shards
			"<Default>Summon %d shards of arcane energy, causing radial arcane damage </>"

			// Damage
			"<Damage>%d</><Default> damage at the shard origins.</>"),

			// Values
			Level,
			ManaCost,
			Cooldown,
			FMath::Min(Level,MaxNumShards),
			ScaledDamage);
}
