#include "GetCurrentAnimationFrame.h"

namespace RB::Sprites
{
	int GetCurrentAnimationFrame(RB::Players::PlayerID id)
	{
		RB::Sprites::SpriteType spriteType = RB::Sprites::GetCurrentSpriteType(RB::Players::PlayerID::PLAYER_1);

		if (RB::Render::iPlayerAnimationController::Get() == nullptr)
		{
			return 0;
		}

		RB::Render::iAnimationObj* obj = RB::Render::iPlayerAnimationController::Get()->GetCurrentAnimationObj(RB::Players::PlayerID::PLAYER_1, spriteType);

		if (obj == nullptr)
		{
			return 0;
		}

		return obj->GetCurrentIndex();
	}
}
