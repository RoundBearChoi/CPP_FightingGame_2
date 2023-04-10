#include "Idle.h"

namespace RB::PlayerStates
{
	Idle::Idle()
	{

	}

	Idle::~Idle()
	{
		//std::cout << "destroying Idle" << std::endl;
	}

	void Idle::OnEnter()
	{

	}

	void Idle::OnUpdate()
	{
		RB::Players::iPlayer* owner = GetOwnerPlayer();

		olc::HWButton button = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(owner->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (button.bPressed)
		{
			std::cout << "D pressed.." << " player: " << static_cast<int>(owner->GetPlayerID()) << std::endl;

			_stateMachine->QueueNextState(new RB::PlayerStates::MoveForward());
		}
	}

	void Idle::OnFixedUpdate()
	{

	}
}