#include "TriggerMoveForward.h"

namespace RB::PlayerStateComponents
{
	TriggerMoveForward::TriggerMoveForward()
	{

	}

	TriggerMoveForward::~TriggerMoveForward()
	{

	}

	void TriggerMoveForward::OnUpdate()
	{
		if (_BothPressed())
		{
			return;
		}

		if (_MoveForwardPressed())
		{
			//std::cout << "player " << (int)_state->GetOwnerPlayer()->GetPlayerID() << " move forward" << std::endl;
		}
	}

	bool TriggerMoveForward::_BothPressed()
	{
		RB::Players::iPlayer* owner = _state->GetOwnerPlayer();

		olc::HWButton moveLeft = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(owner->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(owner->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (moveLeft.bPressed && moveRight.bPressed)
		{
			return true;
		}

		if (moveLeft.bHeld && moveRight.bHeld)
		{
			return true;
		}

		return false;
	}

	bool TriggerMoveForward::_MoveForwardPressed()
	{
		RB::Players::iPlayer* owner = _state->GetOwnerPlayer();

		olc::HWButton moveLeft = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(owner->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(owner->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (owner->OtherPlayerIsOnRightSide())
		{
			if (moveRight.bPressed || moveRight.bHeld)
			{
				return true;
			}
		}
		else
		{
			if (moveLeft.bPressed || moveLeft.bHeld)
			{
				return true;
			}
		}

		return false;
	}
}