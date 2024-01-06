#pragma once
#include <vector>
#include "StateBase.h"
#include "SpriteType.h"

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
		RB::Sprites::SpriteType GetSpriteEnum();
		void AutoUpdatePlayerBox();

	protected:
		RB::Sprites::SpriteType _spriteEnum = RB::Sprites::SpriteType::NONE;
	};
}