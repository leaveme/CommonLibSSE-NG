#pragma once

namespace RE
{
	struct IMapCameraCallbacks
	{
	public:
		inline static auto RTTI = RTTI_IMapCameraCallbacks;

		// add
		virtual void Unk_00(void);  // 00
		virtual void Unk_01(void);  // 01

		virtual ~IMapCameraCallbacks();  // 02
	};
	static_assert(sizeof(IMapCameraCallbacks) == 0x8);
}
