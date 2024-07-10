#include "PlayerBoxRenderer.h"

#include "iPlayerController.h"

namespace RB::Render
{
    void PlayerBoxRenderer::Init(RB::Sprites::SpriteContainer* spriteContainer)
	{
		_spriteContainer = spriteContainer;
	}

	void PlayerBoxRenderer::OnUpdate()
	{
		if (RB::Players::iPlayerController::Get() == nullptr)
		{
			return;
		}

		if (!_renderPlayerBox)
		{
			return;
		}

		for (int i = 0; i < 2; i++)
		{
			RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnIndex(i);

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

			_spriteContainer->RenderSprite(RB::Sprites::SpriteType::white_sq_tr80, playerBox, playerPos, boxTint, RB::Sprites::PivotType::BOTTOM_CENTER, true);
		}
	}

	void PlayerBoxRenderer::OnFixedUpdate()
	{

	}

	void PlayerBoxRenderer::RenderPlayerBox(bool render)
	{
		_renderPlayerBox = render;
	}
}