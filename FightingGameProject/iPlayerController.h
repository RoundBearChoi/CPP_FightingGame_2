#pragma once
#include <iostream>
#include <vector>
#include "olcPixelGameEngine.h"
#include "ControllerBase.h"

#include "iPlayer.h"
#include "iState.h"
#include "PlayerID.h"

namespace RB::Players
{
	class iPlayerController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

	public:
		virtual void AddPlayer(iPlayer* player, RB::States::iState* firstState, olc::vi2d startPos, PlayerID playerID) = 0;

	public:
		virtual iPlayer* GetPlayerOnIndex(size_t index) = 0;
		virtual iPlayer* GetPlayerOnID(PlayerID id) = 0;
		virtual iPlayer* GetPlayerOnStateMachineID(size_t id) = 0;
		virtual iPlayer* GetOtherPlayer(iPlayer* currentPlayer) = 0;
		virtual void SetManualAnimationUpdate(PlayerID id, bool manual) = 0;
	};

	extern iPlayerController* PLAYER_CONTROLLER;
}