#pragma once
#include "iPlayerController.h"
#include "iPlayerDebugController.h"
#include "ControllerGroup.h"

namespace RB::Controllers
{
	class GameplayControllers
	{
	public:
		inline static RB::Players::iPlayerController* PLAYER_CONTROLLER = nullptr;
		inline static RB::PlayerDebug::iPlayerDebugController* PLAYER_DEBUG_CONTROLLER = nullptr;

	public:
		static void FindAll()
		{
			PLAYER_CONTROLLER = ControllerGroup::FindController<RB::Players::iPlayerController>();
			PLAYER_DEBUG_CONTROLLER = ControllerGroup::FindController<RB::PlayerDebug::iPlayerDebugController>();

			//iPlayer* p1 = PLAYER_CONTROLLER->GetPlayerOnPlayerIndex(1);
			//iPlayer* p2 = PLAYER_CONTROLLER->GetPlayerOnPlayerIndex(2);
			//iPlayer* p3 = PLAYER_CONTROLLER->GetPlayerOnPlayerIndex(3);
		}
	};
}