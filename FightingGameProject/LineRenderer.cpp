#include "LineRenderer.h"

namespace RB::Render
{
	void LineRenderer::Init()
	{
		
	}

	void LineRenderer::RenderLine(olc::vf2d p1, olc::vf2d p2, olc::Pixel tint)
	{
		_getter_camController.OnUpdate();

		if (_getter_camController.GetController() == nullptr)
		{
			return;
		}

		olc::vf2d screenPos1;
		olc::vf2d screenPos2;

		screenPos1 = _getter_camController.GetController()->GetCamObj()->GetRelativePosition(p1);
		screenPos2 = _getter_camController.GetController()->GetCamObj()->GetRelativePosition(p2);

		olc::Renderer::ptrPGE->DrawLine(screenPos1, screenPos2, tint);
	}
}