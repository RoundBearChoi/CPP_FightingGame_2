#pragma once
#include <iostream>
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
	private:
		Player _player1;
		Player _player2;

	public:
		PlayerController();
		~PlayerController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		iPlayer* GetPlayerOnID(PlayerID id);
		iPlayer* GetPlayerOnStateMachineID(int id);
	};
}