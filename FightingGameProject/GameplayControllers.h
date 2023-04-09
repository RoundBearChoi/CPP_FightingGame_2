#pragma once
#include "iPlayerController.h"
#include "iPlayer.h"
#include "iPlayerDebugController.h"

using namespace RB::Players;
using namespace RB::PlayerDebug;

namespace RB::Controllers
{
	class GameplayControllers
	{
	public:
		inline static iPlayerController* PLAYER_CONTROLLER = nullptr;
		inline static iPlayerDebugController* PLAYER_DEBUG_CONTROLLER = nullptr;

		static void FindAll()
		{
			PLAYER_CONTROLLER = ControllerGroup::FindController<iPlayerController>();

			iPlayer* p1 = PLAYER_CONTROLLER->GetPlayerOnPlayerIndex(1);
			iPlayer* p2 = PLAYER_CONTROLLER->GetPlayerOnPlayerIndex(2);
			iPlayer* p3 = PLAYER_CONTROLLER->GetPlayerOnPlayerIndex(3);
		}
	};
}