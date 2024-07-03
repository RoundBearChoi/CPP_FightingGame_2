#pragma once
#include <cstdint>

namespace RB::Render
{
	enum class RenderLayerType : uint8_t
	{
		DEFAULT_FOREGROUND = 0,

		DEBUG_ON_TOP_OF_CHARACTERS,
		CHARACTERS,
		DEBUG_BENEATH_CHARACTERS,
		BACKGROUND,

		COUNT,
	};
}
