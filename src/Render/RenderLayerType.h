#pragma once

#include <cstdint>

#include "../olcPixelGameEngine.h"

#include "../GameSettings.h"

namespace RB::Render
{
	enum class RenderLayerType : uint8_t
	{
		DEFAULT_FOREGROUND = 0,

		DECALS,

		COUNT,
	};

	void SetTargetLayer(RenderLayerType layerType);
	void ClearTargetLayer();
	void CreateLayers();
	void ClearLayers();
}