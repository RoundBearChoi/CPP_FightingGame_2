#include "MoveForwardDetector.h"

namespace RB::PlayerStateComponents
{
	MoveForwardDetector::MoveForwardDetector()
	{

	}

	MoveForwardDetector::~MoveForwardDetector()
	{

	}

	void MoveForwardDetector::Init(RB::Players::iPlayer* player)
	{
		_player = player;
	}

	void MoveForwardDetector::OnUpdate()
	{
		if (_BothPressed())
		{
			_moveForward = false;

			return;
		}

		if (_MoveForwardPressed())
		{
			_moveForward = true;

			return;
		}
	}

	bool MoveForwardDetector::_BothPressed()
	{
		olc::HWButton moveLeft = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(_player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(_player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

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

	bool MoveForwardDetector::_MoveForwardPressed()
	{
		olc::HWButton moveLeft = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(_player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(_player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (_player->OtherPlayerIsOnRightSide())
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