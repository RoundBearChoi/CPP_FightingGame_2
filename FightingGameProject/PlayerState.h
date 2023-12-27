#pragma once
#include <vector>

#include "StateBase.h"

#include "iPlayerController.h"
#include "iPlayer.h"

namespace RB::PlayerStates
{
	class PlayerState : public RB::States::StateBase
	{
	public:
		static std::vector<PlayerState*> currentPlayerStates;
		static PlayerState* GetPlayerState(RB::Players::PlayerID playerID);

	public:
		PlayerState();
		~PlayerState() override;

		RB::Players::iPlayer* GetPlayer();
		RB::Sprites::SpriteEnum GetSpriteEnum();

	protected:
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
	};
}