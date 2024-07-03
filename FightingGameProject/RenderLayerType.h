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


	static void SetTargetLayer(RenderLayerType layerType)
	{
		auto& layers = olc::Renderer::ptrPGE->GetLayers();

		uint8_t index = static_cast<uint8_t>(layerType);

		if (layers.size() > index)
		{
			if (layers[index].bShow)
			{
				olc::Renderer::ptrPGE->SetDrawTarget(index);
			}
		}
	}
}
