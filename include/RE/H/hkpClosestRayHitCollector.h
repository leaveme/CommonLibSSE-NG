#pragma once

#include "RE/H/hkpRayHitCollector.h"
#include "RE/H/hkpWorldRayCastOutput.h"

namespace RE
{
	class hkpClosestRayHitCollector : public hkpRayHitCollector
	{
	public:
		inline static auto RTTI = RTTI_hkpClosestRayHitCollector;
		inline static auto VTABLE = VTABLE_hkpClosestRayHitCollector;

		// override (hkpRayHitCollector)
		void AddRayHit(const hkpCdBody& a_body, const hkpShapeRayCastCollectorOutput& a_hitInfo) override;  // 01

		~hkpClosestRayHitCollector() override;  // 00

		// members
		hkpWorldRayCastOutput rayHit;  // 10
	};
	static_assert(sizeof(hkpClosestRayHitCollector) == 0x70);
}
