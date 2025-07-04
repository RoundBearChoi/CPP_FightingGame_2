#include "PlayerBoxRenderer.h"

namespace RB::Render
{
    void PlayerBoxRenderer::Init(Sprites::SpriteContainer* spriteContainer)
	{
		_spriteContainer = spriteContainer;
	}

	void PlayerBoxRenderer::OnUpdate()
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

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
			Players::iPlayer* player = playerController->GetPlayer(Players::PLAYER_TYPE::_from_integral(i));

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
				Sprites::SPRITE_TYPE::white_sq, 
				playerBox.x, 
				playerBox.y, 
				playerPos, 
				boxTint, 
				Sprites::PivotType::BOTTOM_CENTER, 
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
