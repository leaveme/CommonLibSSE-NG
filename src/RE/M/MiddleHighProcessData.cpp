#include "RE/M/MiddleHighProcessData.h"
#include "SKSE/API.h"

namespace RE
{
	void HitData::Populate(Actor* a_aggressor, Actor* a_target, InventoryEntryData* a_weapon)
	{
		using func_t = decltype(&HitData::Populate);
		REL::Relocation<func_t> func(RELOCATION_ID(42832, 44001));
		return func(this, a_aggressor, a_target, a_weapon);
	}
}
