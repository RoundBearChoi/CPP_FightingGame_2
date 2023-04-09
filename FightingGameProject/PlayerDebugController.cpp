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

		olc::Renderer::ptrPGE->DrawLine(pos.x, pos.y, 100, 100, olc::RED);
	}
}