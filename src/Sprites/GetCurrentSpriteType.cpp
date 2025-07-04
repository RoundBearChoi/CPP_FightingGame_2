#include "GetCurrentSpriteType.h"

namespace RB::Sprites
{
	SpriteType GetCurrentSpriteType(Players::PLAYER_TYPE id)
	{
		Players::PlayerState* state = Players::PlayerState::GetPlayerState(id);

		if (state == nullptr)
		{
			return Sprites::SpriteType::NONE;
		}

		Sprites::SpriteType spriteType = state->GetSpriteType();

		return spriteType;
	}
}
