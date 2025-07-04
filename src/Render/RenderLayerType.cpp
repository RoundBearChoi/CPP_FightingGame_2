#include "RenderLayerType.h"

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

	void ClearTargetLayer()
	{
		olc::Renderer::ptrPGE->SetDrawTarget(nullptr);
	}

	void CreateLayers()
	{
		if (!RB::allowMultipleLayers)
		{
			return;
		}

		while (olc::Renderer::ptrPGE->GetLayers().size() < static_cast<uint8_t>(Render::RenderLayerType::COUNT))
		{
			olc::Renderer::ptrPGE->CreateLayer();

			auto& layers = olc::Renderer::ptrPGE->GetLayers();

			layers[layers.size() - 1].bShow = true;
			layers[layers.size() - 1].bUpdate = true;
		}
	}

	void ClearLayers()
	{
		size_t count = olc::Renderer::ptrPGE->GetLayers().size();

		// clear all layers with blank pixels (except top layer)
		for (int i = static_cast<uint8_t>(Render::RenderLayerType::DEFAULT_FOREGROUND); i < static_cast<uint8_t>(Render::RenderLayerType::COUNT); i++)
		{
			if (i >= count)
			{
				continue;
			}

			if (olc::Renderer::ptrPGE->GetLayers()[i].bShow)
			{
				if (i == static_cast<uint8_t>(Render::RenderLayerType::COUNT) - 1)
				{
					olc::Renderer::ptrPGE->SetDrawTarget(i);
					olc::Renderer::ptrPGE->Clear({ 20, 20, 20 });
				}
				else
				{
					olc::Renderer::ptrPGE->SetDrawTarget(i);
					olc::Renderer::ptrPGE->Clear(olc::BLANK);
				}
			}
		}
	}
}
