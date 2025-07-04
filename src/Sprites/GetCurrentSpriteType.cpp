#include "GetCurrentSpriteType.h"

namespace RB::Sprites
{
	Sprites::SPRITE_TYPE GetCurrentSpriteType(Players::PLAYER_TYPE id)
	{
		Players::PlayerState* state = Players::PlayerState::GetPlayerState(id);

		if (state == nullptr)
		{
			return Sprites::SPRITE_TYPE::NONE;
		}

		Sprites::SPRITE_TYPE spriteType = state->GetSpriteType();

		return spriteType;
	}
}
