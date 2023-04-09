#pragma once
#include "iPlayer.h"

using namespace RB::Players;

namespace RB::Controllers
{
	class GameplayControllers
	{
	public:
		inline static iPlayerController* PLAYER_CONTROLLER = nullptr;

		static void FindAll()
		{
			PLAYER_CONTROLLER = ControllerGroup::FindController<iPlayerController>();

			iPlayer* p1 = PLAYER_CONTROLLER->GetPlayerOnPlayerIndex(1);
			iPlayer* p2 = PLAYER_CONTROLLER->GetPlayerOnPlayerIndex(2);
			iPlayer* p3 = PLAYER_CONTROLLER->GetPlayerOnPlayerIndex(3);
		}
	};
}