#pragma once
#include <iostream>
#include <vector>
#include "olcPixelGameEngine.h"
#include "ControllerBase.h"
#include "iPlayer.h"
#include "PlayerID.h"

namespace RB::Players
{
	class PlayerController : public RB::Controllers::ControllerBase
	{
	public:
		PlayerController();
		~PlayerController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		void AddPlayer(iPlayer* player, RB::States::iState* firstState, olc::vi2d startPos, PlayerID playerID);

	public:
		iPlayer* GetPlayerOnIndex(size_t index);
		iPlayer* GetPlayerOnID(PlayerID id);
		iPlayer* GetPlayerOnStateMachineID(size_t id);
		iPlayer* GetOtherPlayer(iPlayer* currentPlayer);
		void SetManualAnimationUpdate(PlayerID id, bool manual);

	private:
		std::vector<RB::Players::iPlayer*> _vecPlayers;
	};
}