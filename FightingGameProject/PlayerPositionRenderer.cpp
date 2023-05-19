#include "PlayerPositionRenderer.h"

namespace RB::Render
{
	void PlayerPositionRenderer::Init(SpriteRenderer* spriteRenderer, LineRenderer* lineRenderer)
	{
		_spriteRenderer = spriteRenderer;
		_lineRenderer = lineRenderer;
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
		
		RenderBottomLeft(RB::Players::PlayerID::PLAYER_1);
		RenderBottomLeft(RB::Players::PlayerID::PLAYER_2);

		RenderAirMomentum(RB::Players::PlayerID::PLAYER_1);
		RenderAirMomentum(RB::Players::PlayerID::PLAYER_2);
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

	void PlayerPositionRenderer::RenderBottomLeft(RB::Players::PlayerID playerID)
	{
		RB::Players::iPlayer* player = _getter_playerController.GetController()->GetPlayerOnID(playerID);

		if (player == nullptr)
		{
			return;
		}

		RB::Collisions::AABB aabb = player->GetAABB();

		_lineRenderer->RenderLine(aabb.GetBottomLeft() - olc::vi2d{ 15, 0 }, aabb.GetBottomLeft(), olc::RED);
	}

	void PlayerPositionRenderer::RenderAirMomentum(RB::Players::PlayerID playerID)
	{
		RB::Players::iPlayer* player = _getter_playerController.GetController()->GetPlayerOnID(playerID);

		if (player == nullptr)
		{
			return;
		}

		olc::vi2d pos = player->GetPosition();
		olc::vf2d airMomentum = player->GetAirMomentum();

		if (airMomentum.y > 0.5f)
		{
			int32_t boxY = player->GetPlayerBox().y;

			pos.y -= boxY;

			_lineRenderer->RenderLine(pos, pos - player->GetAirMomentum(), olc::CYAN);
		}
	}
}