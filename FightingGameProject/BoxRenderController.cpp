#include "BoxRenderController.h"

namespace RB::Render
{
	BoxRenderController::BoxRenderController()
	{

	}

	BoxRenderController::~BoxRenderController()
	{
		delete _boxRenderer;
	}

	void BoxRenderController::Init()
	{
		_boxRenderer = new BoxRenderer();

		_boxRenderer->Init();
	}

	void BoxRenderController::OnUpdate()
	{

	}

	void BoxRenderController::OnFixedUpdate()
	{

	}
	iBoxRenderer* BoxRenderController::GetBoxRenderer()
	{
		return _boxRenderer;
	}

	//void BoxRenderController::RenderBox(olc::vf2d widthHeight, olc::vf2d pos, olc::Pixel color, RB::Sprites::PivotType pivotType)
	//{
	//	_boxRenderer->RenderBox(widthHeight, pos, color, pivotType);
	//}
}