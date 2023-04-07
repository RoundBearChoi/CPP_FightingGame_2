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

	}

	void PlayerController::OnFixedUpdate()
	{

	}
}