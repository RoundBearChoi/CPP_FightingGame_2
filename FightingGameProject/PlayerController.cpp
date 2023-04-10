#include "PlayerController.h"

namespace RB::Players
{
	PlayerController::PlayerController()
	{
		std::cout << "constructing PlayerController" << std::endl;
	}

	PlayerController::~PlayerController()
	{
		std::cout << "destroying PlayerController" << std::endl;
	}

	void PlayerController::Init()
	{
		_player1.Init(PlayerID::PLAYER_1);
		_player2.Init(PlayerID::PLAYER_2);

		_player1.SetPosition(olc::vi2d{ -150, 0 });
		_player2.SetPosition(olc::vi2d{ 150, 0 });
	}

	void PlayerController::OnUpdate()
	{
		_player1.OnUpdate();
		_player2.OnUpdate();
	}

	void PlayerController::OnFixedUpdate()
	{
		_player1.OnFixedUpdate();
		_player2.OnFixedUpdate();
	}

	iPlayer* PlayerController::GetPlayerOnID(PlayerID id)
	{
		if (_player1.GetPlayerID() == id)
		{
			return &_player1;
		}
		else if (_player2.GetPlayerID() == id)
		{
			return &_player2;
		}

		return nullptr;
	}

	iPlayer* PlayerController::GetPlayerOnStateMachineID(int id)
	{
		if (_player1.GetStateMachineID() == id)
		{
			return &_player1;
		}
		else if (_player2.GetStateMachineID() == id)
		{
			return &_player2;
		}

		return nullptr;
	}
}