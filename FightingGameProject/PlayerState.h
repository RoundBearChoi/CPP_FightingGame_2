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
		static size_t playerStateCreationCount;
		static PlayerState* GetPlayerState(RB::Players::PlayerID playerID);

	public:
		PlayerState();
		~PlayerState() override;

		void StandardInit(RB::Sprites::SpriteEnum spriteEnum);
		RB::Sprites::SpriteEnum GetSpriteEnum();
		RB::Players::PlayerID GetPlayerID();
		size_t GetCreationID();

	protected:
		RB::Players::iPlayer* _ownerPlayer = nullptr;
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
		size_t _creationID = 0;
	};
}