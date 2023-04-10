#pragma once
#include "iController.h"
#include "iPlayer.h"
#include "PlayerID.h"

namespace RB::Players
{
	class iPlayerController : public RB::Controllers::iController
	{
	public:
		virtual iPlayer* GetPlayerOnPlayerIndex(PlayerID id) = 0;
		virtual iPlayer* GetPlayerOnStateMachineID(int id) = 0;
	};
}