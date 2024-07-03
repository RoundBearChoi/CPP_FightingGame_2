#include "CircleRenderer.h"

#include "olcPixelGameEngine.h"

#include "iCamController.h"

namespace RB::Render
{
	void CircleRenderer::Init()
	{

	}

	void CircleRenderer::OnFixedUpdate()
	{

	}

	void CircleRenderer::Render(int radius)
	{
		olc::vf2d relPos = RB::Cam::iCamController::Get()->GetCamObj()->GetRelativePosition(_pos) + olc::vf2d{ 1.0, -1.0 };

		olc::Renderer::ptrPGE->DrawCircle(relPos, radius, olc::WHITE);
	}

	void CircleRenderer::SetPos(olc::vf2d pos)
	{
		_pos = pos;
	}
}
