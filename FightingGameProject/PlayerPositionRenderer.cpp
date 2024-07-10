#include "PlayerPositionRenderer.h"

#include "AABB.h"

#include "iPlayerController.h"

namespace RB::Render
{
	void PlayerPositionRenderer::Init(RB::Sprites::SpriteContainer* spriteContainer, LineRenderer* lineRenderer)
	{
		_spriteContainer = spriteContainer;
		_lineRenderer = lineRenderer;
	}

	void PlayerPositionRenderer::OnUpdate()
	{
		if (RB::Players::iPlayerController::Get() == nullptr)
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
		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnID(playerID);

		if (player == nullptr)
		{
			return;
		}

		olc::vf2d playerPos = player->GetPosition();

		_spriteContainer->RenderSprite(RB::Sprites::SpriteType::x_white, 13, 13, playerPos, olc::RED, RB::Sprites::PivotType::CENTER, true);
	}

	void PlayerPositionRenderer::RenderBottomLeft(RB::Players::PlayerID playerID)
	{
		RB::Players::iPlayer* player = RB::Players::iPlayerController::Get()->GetPlayerOnID(playerID);

		if (player == nullptr)
		{
			return;
		}

		RB::Collisions::AABB* aabb = player->GetPlayerCollider()->GetAABB_ptr();
		olc::vf2d bottomLeft = aabb->GetBottomLeft();

		_lineRenderer->RenderLine(bottomLeft - olc::vf2d{ 15.0, 0.0 }, bottomLeft, olc::RED);
	}
}