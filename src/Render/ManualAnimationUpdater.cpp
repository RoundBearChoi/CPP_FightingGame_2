#include "ManualAnimationUpdater.h"

namespace RB::Render
{
	void ManualAnimationUpdater::OnEnter(Sprites::SpriteType spriteType)
	{
		_spriteType = spriteType;
	}

	void ManualAnimationUpdater::OnUpdate()
	{
		Render::iPlayerAnimationController* playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;

		if (playerAnimationController == nullptr)
		{
			return;
		}

		Render::iAnimationObj* aniObj = playerAnimationController->GetCurrentAnimationObj(Players::PLAYER_TYPE::PLAYER_1, _spriteType);

		if (aniObj == nullptr)
		{
			return;
		}

		olc::HWButton up = olc::Platform::ptrPGE->GetKey(olc::Key::PGUP);
		olc::HWButton down = olc::Platform::ptrPGE->GetKey(olc::Key::PGDN);

		if (up.bPressed)
		{
			aniObj->ManualIncreaseAnimationIndex();
		}

		if (down.bPressed)
		{
			aniObj->ManualDecreaseAnimationIndex();
		}
	}

	void ManualAnimationUpdater::OnFixedUpdate()
	{

	}
}
