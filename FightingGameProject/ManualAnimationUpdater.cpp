#include "ManualAnimationUpdater.h"

namespace RB::Render
{
	void ManualAnimationUpdater::OnEnter(RB::Sprites::SpriteEnum spriteEnum)
	{
		_spriteEnum = spriteEnum;
	}

	void ManualAnimationUpdater::OnUpdate()
	{
		if (RB::Render::PlayerAnimationController::PTR == nullptr)
		{
			return;
		}

		RB::Render::PlayerAnimationObj* aniObj = RB::Render::PlayerAnimationController::PTR->GetAnimationObj(RB::Players::PlayerID::PLAYER_1, _spriteEnum);

		if (aniObj == nullptr)
		{
			return;
		}

		olc::HWButton up = olc::Platform::ptrPGE->GetKey(olc::Key::PGUP);
		olc::HWButton down = olc::Platform::ptrPGE->GetKey(olc::Key::PGDN);

		if (up.bPressed)
		{
			aniObj->ManualAddAnimationIndex(1);
		}

		if (down.bPressed)
		{
			aniObj->ManualAddAnimationIndex(-1);
		}
	}

	void ManualAnimationUpdater::OnFixedUpdate()
	{

	}
}