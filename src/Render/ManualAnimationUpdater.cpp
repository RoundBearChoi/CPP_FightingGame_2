#include "ManualAnimationUpdater.h"

namespace RB::Render
{
	void ManualAnimationUpdater::OnEnter(RB::Sprites::SpriteType spriteType)
	{
		_spriteType = spriteType;
	}

	void ManualAnimationUpdater::OnUpdate()
	{
		RB::Render::iPlayerAnimationController* playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;

		if (playerAnimationController == nullptr)
		{
			return;
		}

		RB::Render::iAnimationObj* aniObj = playerAnimationController->GetCurrentAnimationObj(RB::Players::PlayerID::PLAYER_1, _spriteType);

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
