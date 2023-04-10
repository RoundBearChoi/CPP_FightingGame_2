#pragma once
#include <iostream>
#include "iPlayerController.h"
#include "iPlayer.h"
#include "Player.h"
#include "PlayerID.h"

namespace RB::Players
{
	class PlayerController : public iPlayerController
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
		iPlayer* GetPlayerOnID(PlayerID id) override;
		iPlayer* GetPlayerOnStateMachineID(int id) override;
	};
}