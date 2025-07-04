#include "GetCurrentSpriteType.h"

namespace RB::Sprites
{
	SpriteType GetCurrentSpriteType(RB::Players::PLAYER_TYPE id)
	{
		RB::Players::PlayerState* state = RB::Players::PlayerState::GetPlayerState(id);

		if (state == nullptr)
		{
			return Sprites::SpriteType::NONE;
		}

		Sprites::SpriteType spriteType = state->GetSpriteType();

		return spriteType;
	}
}
