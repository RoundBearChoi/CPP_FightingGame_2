#pragma once
#include "iController.h"
#include "iPlayer.h"

namespace RB::Players
{
	class iPlayerController : public RB::Controllers::iController
	{
	public:
		virtual iPlayer* GetPlayerOnPlayerIndex(int index) = 0;
		virtual iPlayer* GetPlayerOnStateMachineID(int ID) = 0;
	};
}