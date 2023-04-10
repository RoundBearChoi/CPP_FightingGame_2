#include "InputController.h"

namespace RB::Input
{
	InputController::InputController()
	{

	}

	InputController::~InputController()
	{

	}

	void InputController::Init()
	{
		//std::cout << "initializing InputController.." << std::endl;

		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_LEFT, olc::A });
		_vecKeyBindings.push_back(KeyBinding{ RB::Players::PlayerID::PLAYER_1, PlayerInput::MOVE_RIGHT, olc::D });
	}

	void InputController::OnUpdate()
	{

	}

	void InputController::OnFixedUpdate()
	{

	}

	olc::HWButton InputController::GetButton(Input::PlayerInput playerInput)
	{
		for (int i = 0; i < _vecKeyBindings.size(); i++)
		{

		}

		return olc::HWButton();
	}
}