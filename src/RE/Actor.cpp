#include "RE/Actor.h"

#include "skse64/GameForms.h"  // TESRace
#include "skse64/GameRTTI.h"  // DYNAMIC_CAST

#include "RE/ExtraFactionChanges.h"  // ExtraFactionChanges
#include "RE/Offsets.h"
#include "RE/TESActorBaseData.h"  // TESActorBaseData
#include "RE/TESFaction.h"  // TESFaction
#include "RE/TESNPC.h"  // TESNPC
#include "RE/TESRace.h"  // TESRace


namespace RE
{
	TESForm* Actor::GetEquippedObject(bool a_abLeftHand)
	{
		typedef TESForm* _GetEquippedObject_t(Actor* a_this, bool a_abLeftHand);
		static _GetEquippedObject_t* _GetEquippedObject = reinterpret_cast<_GetEquippedObject_t*>(GetFnAddr(&::Actor::GetEquippedObject));
		return _GetEquippedObject(this, a_abLeftHand);
	}


	void Actor::UpdateSkinColor()
	{
		typedef void _UpdateSkinColor_t(Actor* a_this);
		static _UpdateSkinColor_t* _UpdateSkinColor = reinterpret_cast<_UpdateSkinColor_t*>(GetFnAddr(&::Actor::UpdateSkinColor));
		_UpdateSkinColor(this);
	}


	void Actor::UpdateHairColor()
	{
		typedef void _UpdateHairColor_t(Actor* a_this);
		static _UpdateHairColor_t* _UpdateHairColor = reinterpret_cast<_UpdateHairColor_t*>(GetFnAddr(&::Actor::UpdateHairColor));
		_UpdateHairColor(this);
	}


	void Actor::QueueNiNodeUpdate(bool a_updateWeight)
	{
		typedef void _QueueNiNodeUpdate_t(Actor* a_this, bool a_updateWeight);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::Actor*>(this)->_QueueNiNodeUpdate_GetPtr());
		static _QueueNiNodeUpdate_t* _QueueNiNodeUpdate = reinterpret_cast<_QueueNiNodeUpdate_t*>(*ptr);
		_QueueNiNodeUpdate(this, a_updateWeight);
	}


	bool Actor::HasPerk(BGSPerk* a_perk)
	{
		typedef bool _HasPerk_t(Actor* a_this, BGSPerk* a_perk);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::Actor*>(this)->_HasPerk_GetPtr());
		static _HasPerk_t* _HasPerk = reinterpret_cast<_HasPerk_t*>(*ptr);
		return _HasPerk(this, a_perk);
	}


	UInt16 Actor::GetLevel()
	{
		typedef UInt16 _GetLevel_t(Actor* a_this);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::Actor*>(this)->_GetLevel_GetPtr());
		static _GetLevel_t* _GetLevel = reinterpret_cast<_GetLevel_t*>(*ptr);
		return _GetLevel(this);
	}


	void Actor::SetRace(TESRace* a_race, bool a_isPlayer)
	{
		typedef void _SetRace_t(Actor* a_this, TESRace* a_race, bool a_isPlayer);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::Actor*>(this)->_SetRace_GetPtr());
		static _SetRace_t* _SetRace = reinterpret_cast<_SetRace_t*>(*ptr);
		_SetRace(this, a_race, a_isPlayer);
	}


	void Actor::UpdateWeaponAbility(TESForm* a_weapon, BaseExtraList* a_extraData, bool a_bLeftHand)
	{
		typedef void _UpdateWeaponAbility_t(Actor* a_this, TESForm* a_weapon, BaseExtraList* a_extraData, bool a_bLeftHand);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::Actor*>(this)->_UpdateWeaponAbility_GetPtr());
		static _UpdateWeaponAbility_t* _UpdateWeaponAbility = reinterpret_cast<_UpdateWeaponAbility_t*>(*ptr);
		_UpdateWeaponAbility(this, a_weapon, a_extraData, a_bLeftHand);
	}


	void Actor::UpdateArmorAbility(TESForm* a_armor, BaseExtraList* a_extraData)
	{
		typedef void _UpdateArmorAbility_t(Actor* a_this, TESForm* a_armor, BaseExtraList* a_extraData);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::Actor*>(this)->_UpdateArmorAbility_GetPtr());
		static _UpdateArmorAbility_t* _UpdateArmorAbility = reinterpret_cast<_UpdateArmorAbility_t*>(*ptr);
		_UpdateArmorAbility(this, a_armor, a_extraData);
	}


	bool Actor::IsHostileToActor(Actor* a_actor)
	{
		typedef bool _IsHostileToActor_t(Actor* a_this, Actor* a_actor);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::Actor*>(this)->_IsHostileToActor_GetPtr());
		static _IsHostileToActor_t* _IsHostileToActor = reinterpret_cast<_IsHostileToActor_t*>(*ptr);
		return _IsHostileToActor(this, a_actor);
	}


	void Actor::ResetAI(UInt32 a_unk1, UInt32 a_unk2)
	{
		typedef void _ResetAI_t(Actor* a_this, UInt32 a_unk1, UInt32 a_unk2);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::Actor*>(this)->_ResetAI_GetPtr());
		static _ResetAI_t* _ResetAI = reinterpret_cast<_ResetAI_t*>(*ptr);
		_ResetAI(this, a_unk1, a_unk2);
	}


	bool Actor::VisitFactions(FactionVisitor& visitor)
	{
		TESNPC* npc = GetActorBase();
		if (npc) {
			for (UInt32 i = 0; i < npc->factions.count; i++) {
				TESActorBaseData::FactionInfo info;
				npc->factions.GetNthItem(i, info);
				if (visitor.Accept(info.faction, info.rank)) {
					return true;
				}
			}

			ExtraFactionChanges* pFactionChanges = static_cast<ExtraFactionChanges*>(extraData.GetByType(kExtraData_FactionChanges));
			if (pFactionChanges) {
				for (UInt32 i = 0; i < pFactionChanges->factions.count; i++) {
					ExtraFactionChanges::FactionInfo info;
					pFactionChanges->factions.GetNthItem(i, info);
					if (visitor.Accept(info.faction, info.rank)) {
						return true;
					}
				}
			}
		}

		return false;
	}


	TESNPC* Actor::GetActorBase()
	{
		return static_cast<TESNPC*>(baseForm);
	}


	TESRace* Actor::GetRace()
	{
		return GetActorBase() ? GetActorBase()->race : 0;
	}


	bool Actor::IsBeingRidden()
	{
		return ((flags2 & kFlags2_HasInteraction) != 0) && extraData.HasType(kExtraData_Interaction);
	}


	bool Actor::IsCommandedActor() const
	{
		return (flags2 & kFlags2_IsCommandedActor) != 0;
	}


	bool Actor::IsEssential() const
	{
		return (flags2 & kFlags2_IsEssential) != 0;
	}


	bool Actor::IsGuard() const
	{
		return (flags1 & kFlags1_IsGuard) != 0;
	}


	bool Actor::IsInKillMove() const
	{
		return (flags2 & kFlags2_IsInKillMove) != 0;
	}


	bool Actor::IsAIEnabled() const
	{
		return (flags1 & kFlags1_AIEnabled) != 0;
	}


	bool Actor::IsOnMount()
	{
		return ((flags2 & kFlags2_HasInteraction) != 0) && extraData.HasType(kExtraData_Interaction);
	}


	bool Actor::IsPlayerTeammate() const
	{
		return (flags1 & kFlags1_IsPlayerTeammate) != 0;
	}


	bool Actor::IsSneaking()
	{
		if (!ActorState::IsSneaking()) {
			return false;
		}

		if (ActorState::IsSwimming()) {
			return false;
		}

		if (IsOnMount()) {
			return false;
		}

		return true;
	}


	bool Actor::IsTrespassing() const
	{
		return (flags2 & kFlags2_IsTrespassing) != 0;
	}


	void Actor::DispelWornItemEnchantments()
	{
		_DispelWornItemEnchantments(this);
	}


	void Actor::SendStealAlarm(TESObjectREFR* a_refItemOrContainer, TESForm* a_stolenItem, UInt32 a_numItems, UInt32 a_value, TESForm* a_owner, bool a_unk)
	{
		_SendStealAlarm(this, a_refItemOrContainer, a_stolenItem, a_numItems, a_value, a_owner, a_unk);
	}


	SInt32 Actor::CalcEntryValue(InventoryEntryData* a_entryData, UInt32 a_numItems, bool a_unk)
	{
		return _CalcEntryValue(this, a_entryData, a_numItems, a_unk);
	}


	SInt32 Actor::GetDetectionLevel(Actor* a_target, UInt32 a_flag)
	{
		return _GetDetectionLevel(this, a_target, a_flag);
	}


	bool Actor::IsGhost()
	{
		return _IsGhost(this);
	}


	bool Actor::IsSummoned()
	{
		return GetActorBase() ? GetActorBase()->IsSummonable() : false;
	}


	RelocAddr<Actor::_DispelWornItemEnchantments_t*> Actor::_DispelWornItemEnchantments(ACTOR_DISPEL_WORN_ITEM_ENCHANTMENTS);
	RelocAddr<Actor::_SendStealAlarm_t*> Actor::_SendStealAlarm(ACTOR_SEND_STEAL_ALARM);
	RelocAddr<Actor::_CalcEntryValue_t*> Actor::_CalcEntryValue(ACTOR_CALC_ENTRY_VALUE);
	RelocAddr<Actor::_GetDetectionLevel_t*> Actor::_GetDetectionLevel(ACTOR_GET_DETECTION_LEVEL);
	RelocAddr<Actor::_IsGhost_t*> Actor::_IsGhost(ACTOR_IS_GHOST);
}
