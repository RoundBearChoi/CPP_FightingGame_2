#include "LineRenderer.h"

#include "iCamController.h"

namespace RB::Render
{
	void LineRenderer::RenderLine(const olc::vf2d& p1, const olc::vf2d& p2, olc::Pixel tint)
	{
		if (RB::Cam::iCamController::instance == nullptr)
		{
			return;
		}

		olc::vf2d screenPos1;
		olc::vf2d screenPos2;

		screenPos1 = RB::Cam::iCamController::instance->GetCamObj()->GetRelativePosition(p1);
		screenPos2 = RB::Cam::iCamController::instance->GetCamObj()->GetRelativePosition(p2);

		olc::Renderer::ptrPGE->DrawLine(screenPos1, screenPos2, tint);
	}
}