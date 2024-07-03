#pragma once
#include <cstdint>

namespace RB::Render
{
	enum class RenderLayerType : uint8_t
	{
		FOREGROUND = 0,	// for debug that's drawn on top of characters, use this layer

		CHARACTERS,
		DEBUG_BENEATH_CHARACTERS,
		BACKGROUND,

		COUNT,
	};
}
