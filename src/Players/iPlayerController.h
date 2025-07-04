#pragma once

#include "iPlayer.h"
#include "PlayerType.h"

#include "../Controllers/ControllerBase.h"

namespace RB::Players
{
	#define GET_PLAYER_CONTROLLER static_cast<Players::iPlayerController*>(Controllers::GetController(Controllers::ControllerType::PLAYER_CONTROLLER))

	class iPlayerController : public Controllers::ControllerBase
	{
	public:
		virtual ~iPlayerController() override {}

	public:
		virtual iPlayer* AddPlayer() = 0;
		virtual iPlayer* GetPlayer(PLAYER_TYPE id) = 0;
		virtual iPlayer* GetPlayerOnStateMachineID(unsigned int id) = 0;
		virtual iPlayer* GetOtherPlayer(iPlayer* currentPlayer) = 0;
	};
}
