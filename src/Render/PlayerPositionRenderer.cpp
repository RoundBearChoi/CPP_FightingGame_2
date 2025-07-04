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
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		if (playerController == nullptr)
		{
			return;
		}

		RenderPosition(Players::PLAYER_TYPE::PLAYER_1);
		RenderPosition(Players::PLAYER_TYPE::PLAYER_2);
		
		RenderBottomLeft(Players::PLAYER_TYPE::PLAYER_1);
		RenderBottomLeft(Players::PLAYER_TYPE::PLAYER_2);
	}

	void PlayerPositionRenderer::OnFixedUpdate()
	{

	}

	void PlayerPositionRenderer::RenderPosition(Players::PLAYER_TYPE playerID)
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		Players::iPlayer* player = playerController->GetPlayer(playerID);

		if (player == nullptr)
		{
			return;
		}

		RB::Vector2 playerPos = player->GetPosition();

		_spriteContainer->RenderSprite(Sprites::SPRITE_TYPE::x_white, 13, 13, playerPos, olc::RED, Sprites::PivotType::CENTER, true);
	}

	void PlayerPositionRenderer::RenderBottomLeft(Players::PLAYER_TYPE playerID)
	{
		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER;

		Players::iPlayer* player = playerController->GetPlayer(playerID);

		if (player == nullptr)
		{
			return;
		}

		RB::Collisions::AABB* aabb = player->GetPlayerCollider()->GetAABB_ptr();
		RB::Vector2 bottomLeft = aabb->GetBottomLeft();

		_lineRenderer->RenderLine(bottomLeft - RB::Vector2{ 15.0f, 0.0f }, bottomLeft, olc::RED);
	}
}
