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

		_spriteRenderer->LoadSprite("PNG files/DebugElements/x_white.png", RB::Sprites::SpriteID::x_white);
		_spriteRenderer->LoadSprite("PNG files/DebugElements/white_sq_tr80.png", RB::Sprites::SpriteID::white_sq_tr80);
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

	iLineRenderer* DebugRenderController::GetLineRenderer()
	{
		return _lineRenderer;
	}
}