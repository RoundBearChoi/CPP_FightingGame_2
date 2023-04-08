#pragma once
#include <iostream>
#include "iPlayerController.h"
#include "iPlayer.h"
#include "Player.h"

using namespace std;

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

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		iPlayer* GetPlayerOnPlayerIndex(int index) override;
	};
}