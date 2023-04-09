#pragma once
#include "iController.h"
#include "iPlayer.h"

using namespace RB::Controllers;

namespace RB::Players
{
	class iPlayerController : public iController
	{
	public:
		virtual iPlayer* GetPlayerOnPlayerIndex(int index) = 0;
		virtual iPlayer* GetPlayerOnStateMachineID(int ID) = 0;
	};
}