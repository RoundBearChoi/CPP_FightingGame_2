#pragma once
#include "ControllerGroup.h"
#include "iInputController.h"
#include "iBoxRenderController.h"
#include "iPlayerController.h"
#include "iPlayerDebugController.h"

namespace RB::Controllers
{
	class GameplayControllers
	{
	public:
		inline static RB::Input::iInputController* INPUT_CONTROLLER = nullptr;
		inline static RB::Render::iBoxRenderController* BOX_RENDER_CONTROLLER = nullptr;
		inline static RB::Players::iPlayerController* PLAYER_CONTROLLER = nullptr;
		inline static RB::PlayerDebug::iPlayerDebugController* PLAYER_DEBUG_CONTROLLER = nullptr;
		//inline static RB::Cam::iGameCamController* GAME_CAM_CONTROLLER = nullptr;

	public:
		static void FindAll()
		{
			INPUT_CONTROLLER = ControllerGroup::FindController<RB::Input::iInputController>();
			BOX_RENDER_CONTROLLER = ControllerGroup::FindController<RB::Render::iBoxRenderController>();
			PLAYER_CONTROLLER = ControllerGroup::FindController<RB::Players::iPlayerController>();
			PLAYER_DEBUG_CONTROLLER = ControllerGroup::FindController<RB::PlayerDebug::iPlayerDebugController>();
			//GAME_CAM_CONTROLLER = ControllerGroup::FindController<RB::Cam::iGameCamController>();
		}
	};
}