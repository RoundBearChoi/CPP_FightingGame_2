#include "PlayerState.h"

namespace RB::PlayerStates
{
	void PlayerState::StandardInit(RB::Sprites::SpriteEnum spriteEnum)
	{
		_spriteEnum = spriteEnum;

		_ownerPlayer = RB::Players::PlayerController::PTR->GetPlayerOnStateMachineID(_stateMachineID);
	}

	RB::Players::PlayerID PlayerState::GetPlayerID()
	{
		if (RB::Players::PlayerController::PTR == nullptr)
		{
			return RB::Players::PlayerID::NONE;
		}
				
		return _ownerPlayer->GetPlayerID();
	}

	RB::Sprites::SpriteEnum PlayerState::GetSpriteEnum()
	{
		return _spriteEnum;
	}
}