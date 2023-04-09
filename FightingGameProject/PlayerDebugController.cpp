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
			_vecPlayers.push_back(pc->GetPlayerOnPlayerIndex(1));
			_vecPlayers.push_back(pc->GetPlayerOnPlayerIndex(2));
		}
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

		olc::vi2d pos = player->GetPosition();

		olc::vi2d topLeft = { pos.x - _lineLength, pos.y - _lineLength };
		olc::vi2d bottomLeft = { pos.x - _lineLength, pos.y + _lineLength };
		olc::vi2d topRight = { pos.x + _lineLength, pos.y - _lineLength };
		olc::vi2d bottomRight = { pos.x + _lineLength, pos.y + _lineLength };

		olc::Renderer::ptrPGE->DrawLine(topLeft.x, topLeft.y, bottomRight.x, bottomRight.y, olc::RED);
		olc::Renderer::ptrPGE->DrawLine(bottomLeft.x, bottomLeft.y, topRight.x, topRight.y, olc::RED);
	}
}