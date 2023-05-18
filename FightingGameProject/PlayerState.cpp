#include "PlayerState.h"

namespace RB::PlayerStates
{
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