#pragma once
#include <vector>

#include "StateBase.h"
#include "SpriteEnum.h"

#include "iPlayer.h"

namespace RB::PlayerStates
{
	class PlayerState : public RB::States::StateBase
	{
	public:
		static std::vector<PlayerState*> allPlayerStates;
		static PlayerState* GetPlayerState(RB::Players::PlayerID playerID);
		static void EraseAll();

	public:
		PlayerState();
		~PlayerState() override;

		void ErasePreviousStates() override;

	public:
		RB::Players::iPlayer* GetPlayer();
		RB::Sprites::SpriteEnum GetSpriteEnum();

	protected:
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
	};
}