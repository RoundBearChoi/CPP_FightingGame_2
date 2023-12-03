#pragma once
#include "StateBase.h"

#include "iPlayerController.h"
#include "iPlayer.h"

namespace RB::PlayerStates
{
	class PlayerState : public RB::States::StateBase
	{
	public:
		~PlayerState() override;

		void StandardInit(RB::Sprites::SpriteEnum spriteEnum);
		RB::Sprites::SpriteEnum GetSpriteEnum();
		RB::Players::PlayerID GetPlayerID();

	protected:
		RB::Players::iPlayer* _ownerPlayer = nullptr;
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
	};
}