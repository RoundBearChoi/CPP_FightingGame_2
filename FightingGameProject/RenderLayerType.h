#pragma once
#include <cstdint>

namespace RB::Render
{
	enum class RenderLayerType : uint8_t
	{
		FOREGROUND = 0,

		DECALS,

		COUNT,
	};
}
