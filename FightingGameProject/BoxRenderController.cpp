#include "BoxRenderController.h"

namespace RB::Render
{
	BoxRenderController::BoxRenderController()
	{

	}

	BoxRenderController::~BoxRenderController()
	{
		delete _spriteRenderer;
	}

	void BoxRenderController::Init()
	{
		_spriteRenderer = new SpriteRenderer();

		_spriteRenderer->Init();
	}

	void BoxRenderController::OnUpdate()
	{

	}

	void BoxRenderController::OnFixedUpdate()
	{

	}
	iSpriteRenderer* BoxRenderController::GetBoxRenderer()
	{
		return _spriteRenderer;
	}
}