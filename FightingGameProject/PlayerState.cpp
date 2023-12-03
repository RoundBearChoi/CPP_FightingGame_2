#include "PlayerState.h"

namespace RB::PlayerStates
{
	PlayerState::~PlayerState()
	{
		for (size_t i = 0; i < _vecStateComponents.size(); i++)
		{
			delete _vecStateComponents[i];
		}

		_vecStateComponents.clear();
	}

	void PlayerState::StandardInit(RB::Sprites::SpriteEnum spriteEnum)
	{
		_spriteEnum = spriteEnum;

		_ownerPlayer = RB::Players::PLAYER_CONTROLLER->GetPlayerOnStateMachineID(_stateMachineID);
	}

	RB::Sprites::SpriteEnum PlayerState::GetSpriteEnum()
	{
		return _spriteEnum;
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
}