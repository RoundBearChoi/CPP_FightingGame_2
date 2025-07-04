#include "GetCurrentAnimationFrame.h"

namespace RB::Sprites
{
	int GetCurrentAnimationFrame(RB::Players::PLAYER_TYPE id)
	{
		Sprites::SpriteType spriteType = Sprites::GetCurrentSpriteType(RB::Players::PLAYER_TYPE::PLAYER_1);

		RB::Render::iPlayerAnimationController* playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;

		if (playerAnimationController == nullptr)
		{
			return 0;
		}

		RB::Render::iAnimationObj* obj = playerAnimationController->GetCurrentAnimationObj(RB::Players::PLAYER_TYPE::PLAYER_1, spriteType);

		if (obj == nullptr)
		{
			return 0;
		}

		return obj->GetCurrentIndex();
	}
}
