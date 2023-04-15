#pragma once
#include "ControllerGroup.h"
#include "iPlayerController.h"
#include "iPlayerDebugController.h"
#include "iPlayerAnimationController.h"

namespace RB::Controllers
{
	class GameplayControllers
	{
	public:
		inline static RB::Players::iPlayerController* PLAYER_CONTROLLER = nullptr;
		inline static RB::PlayerDebug::iPlayerDebugController* PLAYER_DEBUG_CONTROLLER = nullptr;
		inline static RB::Render::iPlayerAnimationController* GAMEPLAY_ANIMATION_CONTROLLER = nullptr;

	public:
		static void FindAll()
		{
			PLAYER_CONTROLLER = ControllerGroup::FindController<RB::Players::iPlayerController>();
			PLAYER_DEBUG_CONTROLLER = ControllerGroup::FindController<RB::PlayerDebug::iPlayerDebugController>();
			GAMEPLAY_ANIMATION_CONTROLLER = ControllerGroup::FindController<RB::Render::iPlayerAnimationController>();
		}
	};
}