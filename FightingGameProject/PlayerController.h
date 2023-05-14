#pragma once
#include <iostream>
#include <vector>
#include "olcPixelGameEngine.h"
#include "ControllerBase.h"
#include "iPlayer.h"
#include "Player.h"
#include "PlayerID.h"
#include "P0_Start.h"

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
		iPlayer* GetPlayerOnIndex(size_t index);
		iPlayer* GetPlayerOnID(PlayerID id);
		iPlayer* GetPlayerOnStateMachineID(size_t id);

	private:
		std::vector<RB::Players::iPlayer*> _vecPlayers;
	};
}