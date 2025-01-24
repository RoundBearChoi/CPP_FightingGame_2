#include "CircleRenderer.h"

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
		auto camController = GET_CAM_CONTROLLER;

		RB::Vector2 relPos = camController->GetCamObj()->GetRelativePosition(_pos) + RB::Vector2{ 1.0f, -1.0f };

		olc::Renderer::ptrPGE->DrawCircle(
			olc::vi2d{ relPos.GetIntX(), relPos.GetIntY() },
			radius, olc::WHITE);
	}

	void CircleRenderer::SetPos(RB::Vector2 pos)
	{
		_pos = pos;
	}
}