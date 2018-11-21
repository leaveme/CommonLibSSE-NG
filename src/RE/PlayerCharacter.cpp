#include "RE/PlayerCharacter.h"

#include "skse64/GameReferences.h"  // PlayerCharacter

#include "RE/Offsets.h"
#include "RE/TESObjectREFR.h"  // TESObjectREFR


namespace RE
{
	TintMask* PlayerCharacter::GetOverlayTintMask(TintMask* a_original)
	{
		typedef TintMask* _GetOverlayTintMask_t(PlayerCharacter* a_this, TintMask* a_original);
		static _GetOverlayTintMask_t* _GetOverlayTintMask = reinterpret_cast<_GetOverlayTintMask_t*>(GetFnAddr(&::PlayerCharacter::GetOverlayTintMask));
		return _GetOverlayTintMask(this, a_original);
	}


	tArray<TintMask*>* PlayerCharacter::GetTintList()
	{
		typedef tArray<TintMask*>* _GetTintList_t(PlayerCharacter* a_this);
		static _GetTintList_t* _GetTintList = reinterpret_cast<_GetTintList_t*>(GetFnAddr(&::PlayerCharacter::GetTintList));
		return _GetTintList(this);
	}


	UInt32 PlayerCharacter::GetNumTints(UInt32 a_tintType)
	{
		typedef UInt32 _GetNumTints_t(PlayerCharacter* a_this, UInt32 a_tintType);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::PlayerCharacter*>(this)->_GetNumTints_GetPtr());
		static _GetNumTints_t* _GetNumTints = reinterpret_cast<_GetNumTints_t*>(*ptr);
		return _GetNumTints(this, a_tintType);
	}


	TintMask* PlayerCharacter::GetTintMask(UInt32 a_tintType, UInt32 a_index)
	{
		typedef TintMask* _GetTintMask_t(PlayerCharacter* a_this, UInt32 a_tintType, UInt32 a_index);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::PlayerCharacter*>(this)->_GetTintMask_GetPtr());
		static _GetTintMask_t* _GetTintMask = reinterpret_cast<_GetTintMask_t*>(*ptr);
		return _GetTintMask(this, a_tintType, a_index);
	}


	float PlayerCharacter::GetDamage(InventoryEntryData* a_pForm)
	{
		typedef float _GetDamage_t(PlayerCharacter* a_this, InventoryEntryData* a_pForm);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::PlayerCharacter*>(this)->_GetDamage_GetPtr());
		static _GetDamage_t* _GetDamage = reinterpret_cast<_GetDamage_t*>(*ptr);
		return _GetDamage(this, a_pForm);
	}


	float PlayerCharacter::GetArmorValue(InventoryEntryData* a_pForm)
	{
		typedef float _GetArmorValue_t(PlayerCharacter* a_this, InventoryEntryData* a_pForm);
		static uintptr_t* ptr = reinterpret_cast<uintptr_t*>(reinterpret_cast<::PlayerCharacter*>(this)->_GetArmorValue_GetPtr());
		static _GetArmorValue_t* _GetArmorValue = reinterpret_cast<_GetArmorValue_t*>(*ptr);
		return _GetArmorValue(this, a_pForm);
	}


	Actor* PlayerCharacter::GetActorInFavorState()
	{
		return _GetActorInFavorState(this);
	}


	TESObjectREFR* PlayerCharacter::GetGrabbedRef()
	{
		TESObjectREFRPtr refPtr;
		UInt32 handle = playerGrabbedHandle;
		if (handle != *g_invalidRefHandle) {
			TESObjectREFR::LookupByHandle(handle, refPtr);
		}
		return refPtr;
	}


	void PlayerCharacter::PlayPickupEvent(TESForm* a_item, TESForm* a_containerOwner, TESObjectREFR* a_containerRef, EventType a_eventType)
	{
		_PlayPickupEvent(this, a_item, a_containerOwner, a_containerRef, a_eventType);
	}


	void PlayerCharacter::StartActivation()
	{
		_StartActivation(this);
	}


	bool PlayerCharacter::TryToPickPocket(Actor* a_target, InventoryEntryData* a_pEntry, UInt32 a_numItems, bool a_unk4)
	{
		return _TryToPickPocket(this, a_target, a_pEntry, a_numItems, a_unk4);
	}


	RelocAddr<PlayerCharacter::_GetActorInFavorState_t*> PlayerCharacter::_GetActorInFavorState(PLAYER_CHARACTER_GET_ACTOR_IN_FAVOR_STATE);
	RelocAddr<PlayerCharacter::_PlayPickupEvent_t*> PlayerCharacter::_PlayPickupEvent(PLAYER_CHARACTER_PLAY_PICKUP_EVENT);
	RelocAddr<PlayerCharacter::_StartActivation_t*> PlayerCharacter::_StartActivation(PLAYER_CHARACTER_START_ACTIVATION);
	RelocAddr<PlayerCharacter::_TryToPickPocket_t*> PlayerCharacter::_TryToPickPocket(PLAYER_CHARACTER_TRY_TO_PICK_POCKET);
}
