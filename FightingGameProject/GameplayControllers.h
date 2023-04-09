#pragma once
#include "iPlayer.h"

using namespace RB::Players;

namespace RB::Controllers
{
	class GameplayControllers
	{
	public:
		static void FindAll()
		{
			iPlayerController* pp = ControllerGroup::FindController<iPlayerController>();

			iPlayer* p1 = pp->GetPlayerOnPlayerIndex(1);
			iPlayer* p2 = pp->GetPlayerOnPlayerIndex(2);
			iPlayer* p3 = pp->GetPlayerOnPlayerIndex(3);
		}
	};
}
