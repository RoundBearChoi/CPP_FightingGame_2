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

		_boxRenderer.Init();
	}

	void PlayerDebugController::OnUpdate()
	{
		for (int i = 0; i < _vecPlayers.size(); i++)
		{
			DrawXOnPlayer(_vecPlayers[i]);
		}
	}

	void PlayerDebugController::OnFixedUpdate()
	{

	}

	void PlayerDebugController::DrawXOnPlayer(RB::Players::iPlayer* player)
	{
		olc::vi2d playerPos = player->GetPosition();
		olc::vi2d relPos = RB::Controllers::GameplayControllers::GAME_CAM_CONTROLLER->GetRelativePos(playerPos);

		olc::vi2d topLeft = { relPos.x - _lineLength, relPos.y - _lineLength };
		olc::vi2d bottomLeft = { relPos.x - _lineLength, relPos.y + _lineLength };
		olc::vi2d topRight = { relPos.x + _lineLength, relPos.y - _lineLength };
		olc::vi2d bottomRight = { relPos.x + _lineLength, relPos.y + _lineLength };

		olc::Renderer::ptrPGE->DrawLine(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y, olc::RED);
		olc::Renderer::ptrPGE->DrawLine(bottomLeft.x, bottomLeft.y, topRight.x, topRight.y, olc::RED);

		_boxRenderer.RenderBox(olc::vi2d{ 50, 50 }, playerPos, olc::WHITE, RB::Sprites::PivotType::CENTER);
		//_boxRenderer.RenderBox(olc::vi2d{ 50, 50 }, playerPos, olc::WHITE, RB::Sprites::PivotType::BOTTOM_CENTER);
	}
}