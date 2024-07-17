#pragma once

#include <cstdint>

namespace RB::Render
{
	enum class RenderLayerType : uint8_t
	{
		DEFAULT_FOREGROUND = 0,

		DECALS,

		COUNT,
	};


	void SetTargetLayer(RenderLayerType layerType);
	void CreateLayers();
	void ClearLayers();
}
