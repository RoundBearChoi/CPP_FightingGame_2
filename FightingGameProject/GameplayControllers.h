#pragma once
#include "ControllerGroup.h"
#include "iInputController.h"
#include "iDebugRenderController.h"
#include "iPlayerController.h"
#include "iPlayerDebugController.h"

namespace RB::Controllers
{
	class GameplayControllers
	{
	public:
		inline static RB::Input::iInputController* INPUT_CONTROLLER = nullptr;
		//inline static RB::Render::iDebugRenderController* DEBUG_RENDER_CONTROLLER = nullptr;
		inline static RB::Players::iPlayerController* PLAYER_CONTROLLER = nullptr;
		inline static RB::PlayerDebug::iPlayerDebugController* PLAYER_DEBUG_CONTROLLER = nullptr;

	public:
		static void FindAll()
		{
			INPUT_CONTROLLER = ControllerGroup::FindController<RB::Input::iInputController>();
			//DEBUG_RENDER_CONTROLLER = ControllerGroup::FindController<RB::Render::iDebugRenderController>();
			PLAYER_CONTROLLER = ControllerGroup::FindController<RB::Players::iPlayerController>();
			PLAYER_DEBUG_CONTROLLER = ControllerGroup::FindController<RB::PlayerDebug::iPlayerDebugController>();
		}
	};
}