#include "PlayerController.h"

namespace RB::Players
{
	PlayerController::PlayerController()
	{
		cout << "constructing PlayerController" << endl;
	}

	PlayerController::~PlayerController()
	{
		cout << "destroying PlayerController" << endl;
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

	iPlayer* PlayerController::GetPlayerOnPlayerID(int ID)
	{
		return nullptr;
	}
}