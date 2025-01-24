#pragma once

#include "iPlayer.h"
#include "PlayerID.h"

#include "../Controllers/ControllerBase.h"

namespace RB::Players
{
	#define GET_PLAYER_CONTROLLER static_cast<RB::Players::iPlayerController*>(RB::Controllers::GetController(Controllers::ControllerType::PLAYER_CONTROLLER))

	class iPlayerController : public RB::Controllers::ControllerBase
	{
	public:
		virtual ~iPlayerController() override {}

		virtual void Init() override {}
		virtual void OnUpdate() override {}
		virtual void OnFixedUpdate() override {}

	public:
		virtual iPlayer* AddPlayer(iPlayer* player) = 0;

	public:
		virtual iPlayer* GetPlayerOnIndex(unsigned int index) = 0;
		virtual iPlayer* GetPlayerOnID(PlayerID id) = 0;
		virtual iPlayer* GetPlayerOnStateMachineID(unsigned int id) = 0;
		virtual iPlayer* GetOtherPlayer(iPlayer* currentPlayer) = 0;
	};
}