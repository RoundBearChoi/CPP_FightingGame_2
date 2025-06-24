#include "PlayerBoxRenderer.h"

namespace RB::Render
{
    void PlayerBoxRenderer::Init(RB::Sprites::SpriteContainer* spriteContainer)
	{
		_spriteContainer = spriteContainer;
	}

	void PlayerBoxRenderer::OnUpdate()
	{
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr)
		{
			return;
		}

		if (!_renderPlayerBox)
		{
			return;
		}

		for (int i = 1; i <= 2; i++)
		{
			RB::Players::iPlayer* player = playerController->GetPlayer(Players::PlayerID::_from_integral(i));

			if (player == nullptr)
			{
				continue;
			}

			RB::Vector2 playerBox = player->GetPlayerCollider()->GetPlayerBox();
			RB::Vector2 playerPos = player->GetPosition();

			olc::Pixel boxTint = olc::YELLOW;

			if (player->GetPlayerCollider()->IsCollidingAgainstOtherPlayer())
			{
				boxTint = olc::BLUE;
			}

			boxTint.a = 40;

			_spriteContainer->RenderSprite(
				RB::Sprites::SpriteType::white_sq, 
				playerBox.x, 
				playerBox.y, 
				playerPos, 
				boxTint, 
				RB::Sprites::PivotType::BOTTOM_CENTER, 
				true);
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
