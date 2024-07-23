#include "GetCurrentSpriteType.h"

namespace RB::Sprites
{
	SpriteType GetCurrentSpriteType(RB::Players::PlayerID id)
	{
		RB::Players::PlayerState* state = RB::Players::PlayerState::GetPlayerState(id);

		if (state == nullptr)
		{
			return RB::Sprites::SpriteType::NONE;
		}

		RB::Sprites::SpriteType spriteType = state->GetSpriteType();

		return spriteType;
	}
}
