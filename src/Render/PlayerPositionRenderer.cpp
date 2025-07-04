#include "PlayerPositionRenderer.h"

namespace RB::Render
{
	void PlayerPositionRenderer::Init(Sprites::SpriteContainer* spriteContainer, LineRenderer* lineRenderer)
	{
		_spriteContainer = spriteContainer;
		_lineRenderer = lineRenderer;
	}

	void PlayerPositionRenderer::OnUpdate()
	{
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr)
		{
			return;
		}

		RenderPosition(RB::Players::PLAYER_TYPE::PLAYER_1);
		RenderPosition(RB::Players::PLAYER_TYPE::PLAYER_2);
		
		RenderBottomLeft(RB::Players::PLAYER_TYPE::PLAYER_1);
		RenderBottomLeft(RB::Players::PLAYER_TYPE::PLAYER_2);
	}

	void PlayerPositionRenderer::OnFixedUpdate()
	{

	}

	void PlayerPositionRenderer::RenderPosition(RB::Players::PLAYER_TYPE playerID)
	{
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		RB::Players::iPlayer* player = playerController->GetPlayer(playerID);

		if (player == nullptr)
		{
			return;
		}

		RB::Vector2 playerPos = player->GetPosition();

		_spriteContainer->RenderSprite(Sprites::SpriteType::x_white, 13, 13, playerPos, olc::RED, Sprites::PivotType::CENTER, true);
	}

	void PlayerPositionRenderer::RenderBottomLeft(RB::Players::PLAYER_TYPE playerID)
	{
		RB::Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		RB::Players::iPlayer* player = playerController->GetPlayer(playerID);

		if (player == nullptr)
		{
			return;
		}

		RB::Collisions::AABB* aabb = player->GetPlayerCollider()->GetAABB_ptr();
		RB::Vector2 bottomLeft = aabb->GetBottomLeft();

		_lineRenderer->RenderLine(bottomLeft - RB::Vector2{ 15.0f, 0.0f }, bottomLeft, olc::RED);
	}
}
