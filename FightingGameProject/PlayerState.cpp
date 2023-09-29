#include "PlayerState.h"

namespace RB::PlayerStates
{
	void PlayerState::StandardInit(RB::Sprites::SpriteEnum spriteEnum)
	{
		_spriteEnum = spriteEnum;

		_ownerPlayer = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachineID);
	}

	RB::Players::PlayerID PlayerState::GetPlayerID()
	{
		if (RB::Players::PLAYER_CONTROLLER == nullptr)
		{
			return RB::Players::PlayerID::NONE;
		}
				
		if (_ownerPlayer == nullptr)
		{
			std::cout << "no owner player" << std::endl;
		}

		return _ownerPlayer->GetPlayerID();
	}

	RB::Sprites::SpriteEnum PlayerState::GetSpriteEnum()
	{
		return _spriteEnum;
	}
}