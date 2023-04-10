#pragma once
#include "iInputController.h"
#include "iPlayerController.h"
#include "iPlayerDebugController.h"
#include "ControllerGroup.h"

namespace RB::Controllers
{
	class GameplayControllers
	{
	public:
		inline static RB::Input::iInputController* INPUT_CONTROLLER = nullptr;
		inline static RB::Players::iPlayerController* PLAYER_CONTROLLER = nullptr;
		inline static RB::PlayerDebug::iPlayerDebugController* PLAYER_DEBUG_CONTROLLER = nullptr;

	public:
		static void FindAll()
		{
			INPUT_CONTROLLER = ControllerGroup::FindController<RB::Input::iInputController>();
			PLAYER_CONTROLLER = ControllerGroup::FindController<RB::Players::iPlayerController>();
			PLAYER_DEBUG_CONTROLLER = ControllerGroup::FindController<RB::PlayerDebug::iPlayerDebugController>();
		}
	};
}