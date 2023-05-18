#include "PlayerState.h"

namespace RB::PlayerStates
{
	void PlayerState::StandardInit(RB::Sprites::SpriteEnum spriteEnum)
	{
		_spriteEnum = spriteEnum;

		_getter_PlayerController.FindController();
		_ownerPlayer = _getter_PlayerController.GetController()->GetPlayerOnStateMachineID(_stateMachineID);
	}

	RB::Players::PlayerID PlayerState::GetPlayerID()
	{
		if (_ownerPlayer == nullptr)
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