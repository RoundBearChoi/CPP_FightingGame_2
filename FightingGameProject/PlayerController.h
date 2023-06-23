#pragma once
#include "iPlayerController.h"
//#include <iostream>
//#include <vector>
//#include "olcPixelGameEngine.h"
//#include "ControllerBase.h"
//#include "iPlayer.h"
//#include "PlayerID.h"

namespace RB::Players
{
	extern iPlayerController* PLAYER_CONTROLLER;

	class PlayerController : public iPlayerController
	{
	public:
		PlayerController();
		~PlayerController() override;
		//static inline PlayerController* PTR = nullptr;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		void AddPlayer(iPlayer* player, RB::States::iState* firstState, olc::vi2d startPos, PlayerID playerID) override;

	public:
		iPlayer* GetPlayerOnIndex(size_t index) override;
		iPlayer* GetPlayerOnID(PlayerID id) override;
		iPlayer* GetPlayerOnStateMachineID(size_t id) override;
		iPlayer* GetOtherPlayer(iPlayer* currentPlayer) override;
		void SetManualAnimationUpdate(PlayerID id, bool manual) override;

	private:
		std::vector<RB::Players::iPlayer*> _vecPlayers;
	};
}