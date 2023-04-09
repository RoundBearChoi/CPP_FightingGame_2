#pragma once
#include "StateBase.h"
//#include "GameplayControllers.h"
//#include "iPlayer.h"

using namespace RB::States;
//using namespace RB::Controllers;
//using namespace RB::Players;

namespace RB::Players
{
	//class iPlayer;
	//class GameplayControllers;

	class PlayerTestState : public StateBase
	{
	public:
		~PlayerTestState() override;

		void OnFixedUpdate() override;
	};
}