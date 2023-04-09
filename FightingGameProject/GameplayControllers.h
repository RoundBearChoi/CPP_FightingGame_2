#pragma once

using namespace RB::Players;

namespace RB::Controllers
{
	class GameplayControllers
	{
	public:
		static void FindAll()
		{
			iPlayerController* pp = ControllerGroup::FindController<iPlayerController>();
		}
	};
}