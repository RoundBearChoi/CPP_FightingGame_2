#include "PlayerPositionRenderer.h"

namespace RB::Render
{
	void PlayerPositionRenderer::Init(SpriteRenderer* spriteRenderer)
	{
		_spriteRenderer = spriteRenderer;
	}

	void PlayerPositionRenderer::OnUpdate()
	{
		_getter_playerController.OnUpdate();

		if (_getter_playerController.GetController() == nullptr)
		{
			return;
		}

		RenderPosition(RB::Players::PlayerID::PLAYER_1);
		RenderPosition(RB::Players::PlayerID::PLAYER_2);
	}

	void PlayerPositionRenderer::OnFixedUpdate()
	{

	}

	void PlayerPositionRenderer::RenderPosition(RB::Players::PlayerID playerID)
	{
		RB::Players::iPlayer* player = _getter_playerController.GetController()->GetPlayerOnID(playerID);

		if (player == nullptr)
		{
			return;
		}

		olc::vi2d playerPos = player->GetPosition();

		_spriteRenderer->RenderSprite(RB::Sprites::SpriteEnum::x_white, olc::vi2d{ 13, 13 }, playerPos, olc::RED, RB::Sprites::PivotType::CENTER);
	}
}