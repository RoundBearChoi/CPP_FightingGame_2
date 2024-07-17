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
		RB::Vector2 relPos = RB::Cam::iCamController::Get()->GetCamObj()->GetRelativePosition(_pos) + RB::Vector2{ 1.0f, -1.0f };

		olc::Renderer::ptrPGE->DrawCircle(
			olc::vi2d{ relPos.GetIntX(), relPos.GetIntY() },
			radius, olc::WHITE);
	}

	void CircleRenderer::SetPos(RB::Vector2 pos)
	{
		_pos = pos;
	}
}
