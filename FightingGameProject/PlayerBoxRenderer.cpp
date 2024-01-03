#include "PlayerBoxRenderer.h"

#include "iPlayerController.h"

namespace RB::Render
{
    void PlayerBoxRenderer::Init(RB::Sprites::SpriteLoader* spriteLoader)
	{
		_spriteLoader = spriteLoader;
	}

	void PlayerBoxRenderer::OnUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}

		for (int i = 0; i < 2; i++)
		{
			RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnIndex(i);

			if (player == nullptr)
			{
				continue;
			}

			olc::vf2d playerBox = player->GetPlayerCollider()->GetPlayerBox();
			olc::vi2d playerPos = player->GetPosition();

			olc::Pixel boxTint = olc::YELLOW;

			if (player->GetPlayerCollider()->IsCollidingAgainstOtherPlayer())
			{
				boxTint = olc::BLUE;
			}

			_spriteLoader->RenderSprite(RB::Sprites::SpriteEnum::white_sq_tr80, playerBox, playerPos, boxTint, RB::Sprites::PivotType::BOTTOM_CENTER);
		}
	}

	void PlayerBoxRenderer::OnFixedUpdate()
	{

	}
}