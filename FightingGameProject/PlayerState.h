#pragma once
#include "StateBase.h"
#include "iPlayer.h"

#include "ControllerGetter.h"
#include "PlayerController.h"

namespace RB::PlayerStates
{
	class PlayerState : public RB::States::StateBase
	{
	public:
		void StandardInit(RB::Sprites::SpriteEnum spriteEnum);
		RB::Sprites::SpriteEnum GetSpriteEnum();
		RB::Players::PlayerID GetPlayerID();

	protected:
		RB::Controllers::ControllerGetter<RB::Players::PlayerController> _getter_playerController;
		RB::Players::iPlayer* _ownerPlayer = nullptr;
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
	};
}