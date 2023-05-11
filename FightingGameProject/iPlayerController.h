#pragma once
#include "ControllerBase.h"
#include "iPlayer.h"
#include "PlayerID.h"

namespace RB::Players
{
	class iPlayerController : public RB::Controllers::ControllerBase
	{
	public:
		iPlayerController() = default;
		~ iPlayerController() override {};

		virtual iPlayer* GetPlayerOnID(PlayerID id) = 0;
		virtual iPlayer* GetPlayerOnStateMachineID(int id) = 0;
	};
}