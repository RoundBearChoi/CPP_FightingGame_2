#include "DebugRenderController.h"

namespace RB::Render
{
	DebugRenderController::DebugRenderController()
	{

	}

	DebugRenderController::~DebugRenderController()
	{
		delete _spriteRenderer;
	}

	void DebugRenderController::Init()
	{
		_spriteRenderer = new SpriteRenderer();

		_spriteRenderer->Init();
	}

	void DebugRenderController::OnUpdate()
	{

	}

	void DebugRenderController::OnFixedUpdate()
	{

	}
	iSpriteRenderer* DebugRenderController::GetSpriteRenderer()
	{
		return _spriteRenderer;
	}
}