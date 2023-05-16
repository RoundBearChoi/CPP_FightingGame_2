#include "ManualAnimationUpdater.h"

namespace RB::Render
{
	void ManualAnimationUpdater::OnEnter(RB::Sprites::SpriteEnum spriteEnum)
	{
		_spriteEnum = spriteEnum;
	}

	void ManualAnimationUpdater::OnUpdate()
	{
		if (_playerAnimationController == nullptr)
		{
			_playerAnimationController = RB::Controllers::ActiveControllers::GetController<RB::Render::PlayerAnimationController>();

			return;
		}

		RB::Render::PlayerAnimationObj* playerAnimationObj = _playerAnimationController->GetAnimationObj(RB::Players::PlayerID::PLAYER_1, _spriteEnum);

		if (playerAnimationObj == nullptr)
		{
			return;
		}

		olc::HWButton up = olc::Platform::ptrPGE->GetKey(olc::Key::PGUP);
		olc::HWButton down = olc::Platform::ptrPGE->GetKey(olc::Key::PGDN);

		if (up.bPressed)
		{
			playerAnimationObj->ManualAddAnimationIndex(1);
		}

		if (down.bPressed)
		{
			playerAnimationObj->ManualAddAnimationIndex(-1);
		}
	}

	void ManualAnimationUpdater::OnFixedUpdate()
	{

	}
}