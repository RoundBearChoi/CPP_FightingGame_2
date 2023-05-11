#pragma once
#include "CurrentControllers.h"
#include "iPlayerController.h"
#include "iPlayerDebugController.h"

namespace RB::Controllers
{
	class GameplayControllers
	{
	public:
		GameplayControllers() = delete;
		~GameplayControllers() = delete;

	public:
		inline static RB::Players::iPlayerController* PLAYER_CONTROLLER = nullptr;
		inline static RB::PlayerDebug::iPlayerDebugController* PLAYER_DEBUG_CONTROLLER = nullptr;

	public:
		static void Init()
		{
			_FindAll();
		}

		static void OnEnd()
		{
			PLAYER_CONTROLLER = nullptr;
			PLAYER_DEBUG_CONTROLLER = nullptr;
		}

	private:
		static void _FindAll()
		{
			PLAYER_CONTROLLER = CurrentControllers::FindController<RB::Players::iPlayerController>();
			PLAYER_DEBUG_CONTROLLER = CurrentControllers::FindController<RB::PlayerDebug::iPlayerDebugController>();
		}
	};
}