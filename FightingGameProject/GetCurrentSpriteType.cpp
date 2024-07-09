#include "GetCurrentSpriteType.h"

#include "PlayerState.h"

namespace RB::Sprites
{
	SpriteType GetCurrentSpriteType(RB::Players::PlayerID id)
	{
		RB::PlayerStates::PlayerState* state = RB::PlayerStates::PlayerState::GetPlayerState(id);

		if (state == nullptr)
		{
			return RB::Sprites::SpriteType::NONE;
		}

		RB::Sprites::SpriteType spriteType = state->GetSpriteType();

		return spriteType;
	}
}
