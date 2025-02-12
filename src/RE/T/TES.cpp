#include "RE/T/TES.h"

#include "RE/B/bhkPickData.h"
#include "RE/G/GridCellArray.h"
#include "RE/N/NiAVObject.h"
#include "RE/T/TESObjectCELL.h"
#include "RE/T/TESObjectREFR.h"
#include "RE/T/TESWorldspace.h"

namespace RE
{
	TES* TES::GetSingleton()
	{
		REL::Relocation<TES**> singleton{ Offset::TES::Singleton };
		return *singleton;
	}

	void TES::ForEachReference(std::function<bool(TESObjectREFR& a_ref)> a_callback)
	{
		if (interiorCell) {
			interiorCell->ForEachReference([&](TESObjectREFR& a_ref) {
				return a_callback(a_ref);
			});
		} else {
			if (const auto gridLength = gridCells ? gridCells->length : 0; gridLength > 0) {
				std::uint32_t x = 0;
				do {
					std::uint32_t y = 0;
					do {
						const auto cell = gridCells->GetCell(x, y);
						if (cell && cell->IsAttached()) {
							cell->ForEachReference([&](TESObjectREFR& a_ref) {
								return a_callback(a_ref);
							});
						}
						++y;
					} while (y < gridLength);
					++x;
				} while (x < gridLength);
			}
		}
		if (const auto skyCell = worldSpace ? worldSpace->GetSkyCell() : nullptr; skyCell) {
			skyCell->ForEachReference([&](TESObjectREFR& a_ref) {
				return a_callback(a_ref);
			});
		}
	}

	void TES::ForEachReferenceInRange(TESObjectREFR* a_origin, float a_radius, std::function<bool(TESObjectREFR& a_ref)> a_callback)
	{
		if (a_origin && a_radius > 0.0f) {
			const auto originPos = a_origin->GetPosition();
			const auto radiusSquared = a_radius * a_radius;

			if (interiorCell) {
				interiorCell->ForEachReferenceInRange(originPos, radiusSquared, [&](TESObjectREFR& a_ref) {
					return a_callback(a_ref);
				});
			} else {
				if (const auto gridLength = gridCells ? gridCells->length : 0; gridLength > 0) {
					const float yPlus = originPos.y + a_radius;
					const float yMinus = originPos.y - a_radius;
					const float xPlus = originPos.x + a_radius;
					const float xMinus = originPos.x - a_radius;

					std::uint32_t x = 0;
					do {
						std::uint32_t y = 0;
						do {
							auto cell = gridCells->GetCell(x, y);
							if (cell && cell->IsAttached()) {
								const auto cellCoords = cell->GetCoordinates();
								if (cellCoords) {
									const NiPoint2 worldPos{ cellCoords->worldX, cellCoords->worldY };
									if (worldPos.x < xPlus && (worldPos.x + 4096.0f) > xMinus && worldPos.y < yPlus && (worldPos.y + 4096.0f) > yMinus) {
										cell->ForEachReferenceInRange(originPos, radiusSquared, [&](TESObjectREFR& a_ref) {
											return a_callback(a_ref);
										});
									}
								}
							}
							++y;
						} while (y < gridLength);
						++x;
					} while (x < gridLength);
				}
			}

			if (const auto skyCell = worldSpace ? worldSpace->GetSkyCell() : nullptr; skyCell) {
				skyCell->ForEachReferenceInRange(originPos, radiusSquared, [&](TESObjectREFR& a_ref) {
					return a_callback(a_ref);
				});
			}
		} else {
			ForEachReference([&](TESObjectREFR& a_ref) {
				return a_callback(a_ref);
			});
		}
	}

	TESObjectCELL* TES::GetCell(const NiPoint3& a_position) const
	{
		using func_t = decltype(&TES::GetCell);
		REL::Relocation<func_t> func{ RELOCATION_ID(13177, 13322) };
		return func(this, a_position);
	}

	TESLandTexture* TES::GetLandTexture(const NiPoint3& a_position) const
	{
		using func_t = decltype(&TES::GetLandTexture);
		REL::Relocation<func_t> func{ RELOCATION_ID(13202, 13348) };
		return func(this, a_position);
	}

	MATERIAL_ID TES::GetLandMaterialType(const NiPoint3& a_position) const
	{
		using func_t = decltype(&TES::GetLandMaterialType);
		REL::Relocation<func_t> func{ RELOCATION_ID(13203, 13349) };
		return func(this, a_position);
	}

	float TES::GetWaterHeight(const NiPoint3& a_pos, TESObjectCELL* a_cell) const
	{
		using func_t = decltype(&TES::GetWaterHeight);
		REL::Relocation<func_t> func{ RELOCATION_ID(13212, 13358) };
		return func(this, a_pos, a_cell);
	}

	NiAVObject* TES::Pick(bhkPickData& a_pickData)
	{
		using func_t = decltype(&TES::Pick);
		REL::Relocation<func_t> func{ RELOCATION_ID(13221, 13371) };
		return func(this, a_pickData);
	}

	void TES::PurgeBufferedCells()
	{
		using func_t = decltype(&TES::PurgeBufferedCells);
		REL::Relocation<func_t> func{ RELOCATION_ID(13159, 13299) };
		return func(this);
	}
}
