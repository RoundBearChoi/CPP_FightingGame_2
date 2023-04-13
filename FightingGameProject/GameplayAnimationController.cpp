#include "GameplayAnimationController.h"

namespace RB::Render
{
	GameplayAnimationController::GameplayAnimationController()
	{

	}

	GameplayAnimationController::~GameplayAnimationController()
	{
		for (int i = 0; i < _vecAnimationObjs.size(); i++)
		{
			delete _vecAnimationObjs[i];
		}
	}

	void GameplayAnimationController::Init()
	{
		//sprite renderer
		_spriteRenderer.Init();
		_spriteRenderer.LoadSprite("PNG files/Fighter_0/fighter_0_idle.png", RB::Sprites::SpriteID::fighter_0_idle);

		//animation renderer
		_animationRenderer.Init();
		_animationRenderer.LoadAnimation(5, 1, 5, RB::Sprites::SpriteID::fighter_0_idle);
	}

	void GameplayAnimationController::OnUpdate()
	{
		for (int i = 0; i < _vecAnimationObjs.size(); i++)
		{
			_vecAnimationObjs[i]->OnUpdate();
		}
	}

	void GameplayAnimationController::OnFixedUpdate()
	{
		for (int i = 0; i < _vecAnimationObjs.size(); i++)
		{
			_vecAnimationObjs[i]->OnFixedUpdate();
		}
	}
}