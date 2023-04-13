#include "PlayerAnimationController.h"

namespace RB::Render
{
	PlayerAnimationController::PlayerAnimationController()
	{

	}

	PlayerAnimationController::~PlayerAnimationController()
	{
		for (int i = 0; i < _vecAnimationObjs.size(); i++)
		{
			delete _vecAnimationObjs[i];
		}
	}

	void PlayerAnimationController::Init()
	{
		//sprite renderer
		_spriteRenderer.Init();
		_spriteRenderer.LoadSprite("PNG files/Fighter_0/fighter_0_idle.png", RB::Sprites::SpriteID::fighter_0_idle);

		//animation renderer
		_animationRenderer.Init();
		_animationRenderer.LoadAnimation(5, 1, 5, RB::Sprites::SpriteID::fighter_0_idle);
	}

	void PlayerAnimationController::OnUpdate()
	{
		for (int i = 0; i < _vecAnimationObjs.size(); i++)
		{
			_vecAnimationObjs[i]->OnUpdate();
		}
	}

	void PlayerAnimationController::OnFixedUpdate()
	{
		for (int i = 0; i < _vecAnimationObjs.size(); i++)
		{
			_vecAnimationObjs[i]->OnFixedUpdate();
		}
	}
}