#include "PlayerPositionRenderer.h"

namespace RB::Render
{
	void PlayerPositionRenderer::Init(Sprites* spriteRenderer, LineRenderer* lineRenderer)
	{
		_spriteObj = spriteRenderer;
		_lineRenderer = lineRenderer;
	}

	void PlayerPositionRenderer::OnUpdate()
	{
		if (RB::Players::iPlayerController::instance == nullptr)
		{
			return;
		}

		RenderPosition(RB::Players::PlayerID::PLAYER_1);
		RenderPosition(RB::Players::PlayerID::PLAYER_2);
		
		RenderBottomLeft(RB::Players::PlayerID::PLAYER_1);
		RenderBottomLeft(RB::Players::PlayerID::PLAYER_2);
	}

	void PlayerPositionRenderer::OnFixedUpdate()
	{

	}

	void PlayerPositionRenderer::RenderPosition(RB::Players::PlayerID playerID)
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnID(playerID);

		if (player == nullptr)
		{
			return;
		}

		olc::vi2d playerPos = player->GetPosition();

		_spriteObj->RenderSprite(RB::Sprites::SpriteEnum::x_white, olc::vi2d{ 13, 13 }, playerPos, olc::RED, RB::Sprites::PivotType::CENTER);
	}

	void PlayerPositionRenderer::RenderBottomLeft(RB::Players::PlayerID playerID)
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnID(playerID);

		if (player == nullptr)
		{
			return;
		}

		RB::Collisions::AABB aabb = player->UpdateAABBOnPlayerPos();

		_lineRenderer->RenderLine(aabb.GetBottomLeft() - olc::vi2d{ 15, 0 }, aabb.GetBottomLeft(), olc::RED);
	}
}