#include "GetCurrentAnimationFrame.h"

namespace RB::Sprites
{
	int GetCurrentAnimationFrame(Players::PLAYER_TYPE id)
	{
		Sprites::SpriteType spriteType = Sprites::GetCurrentSpriteType(Players::PLAYER_TYPE::PLAYER_1);

		Render::iPlayerAnimationController* playerAnimationController = GET_PLAYER_ANIMATION_CONTROLLER;

		if (playerAnimationController == nullptr)
		{
			return 0;
		}

		Render::iAnimationObj* obj = playerAnimationController->GetCurrentAnimationObj(Players::PLAYER_TYPE::PLAYER_1, spriteType);

		if (obj == nullptr)
		{
			return 0;
		}

		return obj->GetCurrentIndex();
	}
}
