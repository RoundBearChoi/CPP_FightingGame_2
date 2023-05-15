#pragma once
#include "olcPixelGameEngine.h"
#include "StateBase.h"
#include "ActiveControllers.h"
#include "PlayerAnimationController.h"

namespace RB::P0_States
{
	class P0_Idle_Dummy : public RB::States::StateBase
	{
	public:
		P0_Idle_Dummy()
		{
			_spriteID = RB::Sprites::SpriteID::fighter_0_idle;
		}

		~P0_Idle_Dummy() = default;

	public:
		void OnUpdate() override
		{
			if (_playerAnimationController == nullptr)
			{
				_playerAnimationController = RB::Controllers::ActiveControllers::GetController<RB::Render::PlayerAnimationController>();

				return;
			}

			RB::Render::PlayerAnimationObj* playerAnimationObj = _playerAnimationController->GetAnimationObj(RB::Players::PlayerID::PLAYER_1, _spriteID);

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

	private:
		RB::Render::PlayerAnimationController* _playerAnimationController = nullptr;
	};
}