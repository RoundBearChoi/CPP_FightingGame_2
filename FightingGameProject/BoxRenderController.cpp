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
}