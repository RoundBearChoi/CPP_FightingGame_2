#include "LineRenderer.h"

namespace RB::Render
{
	void LineRenderer::Init()
	{
		
	}

	void LineRenderer::RenderLine(olc::vf2d p1, olc::vf2d p2, olc::Pixel tint)
	{
		if (RB::Cam::CamController::PTR == nullptr)
		{
			return;
		}

		olc::vf2d screenPos1;
		olc::vf2d screenPos2;

		screenPos1 = RB::Cam::CamController::PTR->GetCamObj()->GetRelativePosition(p1);
		screenPos2 = RB::Cam::CamController::PTR->GetCamObj()->GetRelativePosition(p2);

		olc::Renderer::ptrPGE->DrawLine(screenPos1, screenPos2, tint);
	}
}