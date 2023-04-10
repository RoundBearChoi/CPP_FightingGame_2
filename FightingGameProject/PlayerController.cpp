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
		_player1.Init(1);
		_player2.Init(2);
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

	iPlayer* PlayerController::GetPlayerOnPlayerIndex(int index)
	{
		if (_player1.GetPlayerID() == index)
		{
			return &_player1;
		}
		else if (_player2.GetPlayerID() == index)
		{
			return &_player2;
		}

		return nullptr;
	}

	iPlayer* PlayerController::GetPlayerOnStateMachineID(int ID)
	{
		if (_player1.GetStateMachineID() == ID)
		{
			return &_player1;
		}
		else if (_player2.GetStateMachineID() == ID)
		{
			return &_player2;
		}

		return nullptr;
	}
}