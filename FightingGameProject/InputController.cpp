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

	olc::HWButton InputController::GetButton(RB::Players::PlayerID playerID, Input::PlayerInput playerInput)
	{
		for (int i = 0; i < _vecKeyBindings.size(); i++)
		{
			if (_vecKeyBindings[i].GetPlayerID() == playerID)
			{
				if (_vecKeyBindings[i].GetPlayerInput() == playerInput)
				{
					olc::Key key = _vecKeyBindings[i].GetKey();
					
					olc::HWButton button = olc::Platform::ptrPGE->GetKey(key);

					return button;
				}
			}
		}

		return olc::HWButton();
	}
}