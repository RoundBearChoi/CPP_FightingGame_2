#include "PlayerDebugController.h"

namespace RB::PlayerDebug
{
	PlayerDebugController::PlayerDebugController()
	{

	}

	PlayerDebugController::~PlayerDebugController()
	{

	}

	void PlayerDebugController::Init()
	{
		RB::Players::iPlayerController* pc = RB::Controllers::ControllerGroup::FindController<RB::Players::iPlayerController>();

		if (pc != nullptr)
		{
			_vecPlayers.push_back(pc->GetPlayerOnID(RB::Players::PlayerID::PLAYER_1));
			_vecPlayers.push_back(pc->GetPlayerOnID(RB::Players::PlayerID::PLAYER_2));
		}
	}

	void PlayerDebugController::OnUpdate()
	{
		for (int i = 0; i < _vecPlayers.size(); i++)
		{
			DrawPlayerBox(_vecPlayers[i]);
			DrawPlayerPosition(_vecPlayers[i]);
			DrawPlayerBottomLeft(_vecPlayers[i]);
			DrawPlayerAirMomentum(_vecPlayers[i]);
		}
	}

	void PlayerDebugController::OnFixedUpdate()
	{

	}

	void PlayerDebugController::DrawPlayerPosition(RB::Players::iPlayer* player)
	{
		olc::vi2d playerPos = player->GetPosition();

		RB::Controllers::GameplayControllers::DEBUG_RENDER_CONTROLLER->GetSpriteRenderer()->
			RenderSprite(RB::Sprites::SpriteID::x_white, olc::vi2d{ 13, 13 }, playerPos, olc::RED, RB::Sprites::PivotType::CENTER);
	}

	void PlayerDebugController::DrawPlayerBox(RB::Players::iPlayer* player)
	{
		olc::vi2d playerBox = player->GetPlayerBox();
		olc::vi2d playerPos = player->GetPosition();

		olc::Pixel boxTint = olc::GREEN;
		if (player->IsCollidingAgainstOtherPlayer())
		{
			boxTint = olc::BLUE;
		}

		RB::Controllers::GameplayControllers::DEBUG_RENDER_CONTROLLER->GetSpriteRenderer()->
			RenderSprite(RB::Sprites::SpriteID::white_sq_tr80, playerBox, playerPos, boxTint, RB::Sprites::PivotType::BOTTOM_CENTER);
	}

	void PlayerDebugController::DrawPlayerBottomLeft(RB::Players::iPlayer* player)
	{
		RB::Collisions::AABB aabb = player->GetAABB();

		RB::Controllers::GameplayControllers::DEBUG_RENDER_CONTROLLER->GetLineRenderer()->
			RenderLine(aabb.GetBottomLeft() - olc::vi2d{ 15, 0 }, aabb.GetBottomLeft(), olc::RED);
	}

	void PlayerDebugController::DrawPlayerAirMomentum(RB::Players::iPlayer* player)
	{
		olc::vi2d pos = player->GetPosition();
		olc::vf2d airMomentum = player->GetAirMomentum();

		if (airMomentum.y > 0.5f)
		{
			int32_t boxY = player->GetPlayerBox().y;

			pos.y -= boxY;

			RB::Controllers::GameplayControllers::DEBUG_RENDER_CONTROLLER->GetLineRenderer()->
				RenderLine(pos, pos - player->GetAirMomentum(), olc::CYAN);
		}
	}
}