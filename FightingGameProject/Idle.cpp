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

		olc::HWButton moveLeft = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(owner->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(owner->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (moveLeft.bPressed && moveRight.bPressed)
		{
			// do nothing
		}
		else if (moveLeft.bPressed)
		{
			_stateMachine->QueueNextState(new RB::PlayerStates::MoveBack());
		}
		else if (moveRight.bPressed)
		{
			_stateMachine->QueueNextState(new RB::PlayerStates::MoveForward());
		}
	}

	void Idle::OnFixedUpdate()
	{

	}
}