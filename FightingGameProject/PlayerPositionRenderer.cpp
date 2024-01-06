#include "PlayerPositionRenderer.h"

#include "AABB.h"

#include "iPlayerController.h"

namespace RB::Render
{
	void PlayerPositionRenderer::Init(RB::Sprites::SpriteLoader* spriteLoader, LineRenderer* lineRenderer)
	{
		_spriteLoader = spriteLoader;
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

		olc::vf2d playerPos = player->GetPosition();

		_spriteLoader->RenderSprite(RB::Sprites::SpriteType::x_white, olc::vf2d{ 13.0, 13.0 }, playerPos, olc::RED, RB::Sprites::PivotType::CENTER);
	}

	void PlayerPositionRenderer::RenderBottomLeft(RB::Players::PlayerID playerID)
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::instance->GetPlayerOnID(playerID);

		if (player == nullptr)
		{
			return;
		}

		RB::Collisions::AABB* aabb = player->GetPlayerCollider()->GetAABB_ptr();
		olc::vf2d bottomLeft = aabb->GetBottomLeft();

		_lineRenderer->RenderLine(bottomLeft - olc::vf2d{ 15.0, 0.0 }, bottomLeft, olc::RED);
	}
}