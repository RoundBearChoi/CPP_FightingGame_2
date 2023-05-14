#include "LineRenderer.h"

namespace RB::Render
{
	void LineRenderer::Init()
	{
		
	}

	void LineRenderer::RenderLine(olc::vf2d p1, olc::vf2d p2, olc::Pixel tint)
	{
		if (_camController == nullptr)
		{
			_camController = RB::Controllers::ActiveControllers::GetController<RB::Cam::CamController>();

			return;
		}

		olc::vi2d screenPos1;
		olc::vi2d screenPos2;

		screenPos1 = _camController->GetCamObj()->GetRelativePosition(p1);
		screenPos2 = _camController->GetCamObj()->GetRelativePosition(p2);

		olc::Renderer::ptrPGE->DrawLine(screenPos1, screenPos2, tint);
	}
}