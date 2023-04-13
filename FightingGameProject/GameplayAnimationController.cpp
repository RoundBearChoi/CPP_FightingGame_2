#include "GameplayAnimationController.h"

namespace RB::Animations
{
	GameplayAnimationController::GameplayAnimationController()
	{

	}

	GameplayAnimationController::~GameplayAnimationController()
	{
		delete _spriteRenderer;
	}

	void GameplayAnimationController::Init()
	{
		_spriteRenderer = new RB::Render::SpriteRenderer();
	}

	void GameplayAnimationController::OnUpdate()
	{

	}

	void GameplayAnimationController::OnFixedUpdate()
	{

	}
}