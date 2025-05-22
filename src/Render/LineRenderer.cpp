#include "LineRenderer.h"

#include "../Cam/GetRelPos.h"

namespace RB::Render
{
	void LineRenderer::RenderLine(const RB::Vector2& p1, const RB::Vector2& p2, olc::Pixel tint)
	{
		auto camController = GET_CAM_CONTROLLER;

		if (camController == nullptr)
		{
			return;
		}

		RB::Vector2 screenPos1;
		RB::Vector2 screenPos2;

		screenPos1 = RB::Cam::GetRelPos(camController->GetCamObj(), p1); //->GetRelativePosition(p1);
		screenPos2 = RB::Cam::GetRelPos(camController->GetCamObj(), p2); //->GetRelativePosition(p2);

		olc::Renderer::ptrPGE->DrawLine(
			olc::vi2d{ screenPos1.GetIntX(), screenPos1.GetIntY() },
			olc::vi2d{ screenPos2.GetIntX(), screenPos2.GetIntY() },
			tint);
	}
}