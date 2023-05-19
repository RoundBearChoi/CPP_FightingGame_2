#include "PlayerBoxRenderer.h"

namespace RB::Render
{
    void PlayerBoxRenderer::Init(SpriteRenderer* spriteRenderer)
	{
		_spriteRenderer = spriteRenderer;
	}

	void PlayerBoxRenderer::OnUpdate()
	{
		_getter_playerController.OnUpdate();

		if (_getter_playerController.GetController() == nullptr)
		{
			return;
		}

		for (int32_t i = 0; i < 2; i++)
		{
			RB::Players::iPlayer* player = _getter_playerController.GetController()->GetPlayerOnIndex(i);

			if (player == nullptr)
			{
				continue;
			}

			olc::vi2d playerBox = player->GetPlayerBox();
			olc::vi2d playerPos = player->GetPosition();

			olc::Pixel boxTint = olc::GREEN;

			if (player->IsCollidingAgainstOtherPlayer())
			{
				boxTint = olc::BLUE;
			}

			_spriteRenderer->RenderSprite(RB::Sprites::SpriteEnum::white_sq_tr80, playerBox, playerPos, boxTint, RB::Sprites::PivotType::BOTTOM_CENTER);
		}
	}

	void PlayerBoxRenderer::OnFixedUpdate()
	{

	}
}