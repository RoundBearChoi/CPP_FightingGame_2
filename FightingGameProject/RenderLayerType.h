#pragma once

#include <cstdint>

#include "olcPixelGameEngine.h"

namespace RB::Render
{
	enum class RenderLayerType : uint8_t
	{
		FOREGROUND = 0,

		DECALS,

		COUNT,
	};


	void SetTargetLayer(RenderLayerType layerType);
}
