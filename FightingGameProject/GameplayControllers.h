#pragma once

using namespace RB::Players;

namespace RB::Controllers
{
	class GameplayControllers
	{
	public:
		static iPlayerController* PLAYER_CONTROLLER;

		static void FindAll()
		{
			//PLAYER_CONTROLLER = ControllerGroup::FindController<iPlayerController>();
		}
	};
}