#include "RenderLayerType.h"

#include "GameSettings.h"

namespace RB::Render
{
	void SetTargetLayer(RenderLayerType layerType)
	{
		if (RB::allowMultipleLayers)
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
		else
		{
			olc::Renderer::ptrPGE->SetDrawTarget(nullptr);
		}
	}
}
