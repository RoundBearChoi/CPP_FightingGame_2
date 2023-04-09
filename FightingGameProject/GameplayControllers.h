#pragma once
#include "iPlayerController.h"

using namespace RB::Players;
using namespace RB::Controllers;

namespace RB::Controllers
{
	class GameplayControllers
	{
	public:
		static iPlayerController* PLAYER_CONTROLLER;

		static void FindAll()
		{
			//iPlayerController* pp = ControllerGroup::FindController<iPlayerController>();
		}
	};
}