#include "BoxRenderController.h"

namespace RB::Render
{
	BoxRenderController::BoxRenderController()
	{

	}

	BoxRenderController::~BoxRenderController()
	{

	}
	void BoxRenderController::Init()
	{
		_boxRenderer.Init();
	}

	void BoxRenderController::OnUpdate()
	{

	}

	void BoxRenderController::OnFixedUpdate()
	{

	}
	void BoxRenderController::RenderBox(olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel color, RB::Sprites::PivotType pivotType)
	{
		_boxRenderer.RenderBox(widthHeight, pos, color, pivotType);
	}
}