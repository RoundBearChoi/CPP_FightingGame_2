#include "MoveBackDetector.h"

namespace RB::PlayerStateComponents
{
	void MoveBackDetector::Init(RB::Players::iPlayer* player)
	{
		_player = player;
	}

	void MoveBackDetector::OnUpdate()
	{
		//false by default
		_moveBack = false;

		if (_BothPressed())
		{
			_moveBack = false;

			return;
		}

		if (_MoveBackPressed())
		{
			_moveBack = true;

			return;
		}
	}

	bool MoveBackDetector::MoveBack()
	{
		return _moveBack;
	}

	bool MoveBackDetector::_BothPressed()
	{
		std::string name = typeid(RB::Input::InputController).name();
		RB::Controllers::iController* inputController = RB::Controllers::CurrentControllers::GetController(std::hash<std::string>{}(name));
		RB::Input::InputController* ic = dynamic_cast<RB::Input::InputController*>(inputController);

		olc::HWButton moveLeft = ic->GetButton(_player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = ic->GetButton(_player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

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

	bool MoveBackDetector::_MoveBackPressed()
	{
		std::string name = typeid(RB::Input::InputController).name();
		RB::Controllers::iController* inputController = RB::Controllers::CurrentControllers::GetController(std::hash<std::string>{}(name));
		RB::Input::InputController* ic = dynamic_cast<RB::Input::InputController*>(inputController);

		olc::HWButton moveLeft = ic->GetButton(_player->GetPlayerID(), RB::Input::PlayerInput::MOVE_LEFT);
		olc::HWButton moveRight = ic->GetButton(_player->GetPlayerID(), RB::Input::PlayerInput::MOVE_RIGHT);

		if (_player->OtherPlayerIsOnRightSide())
		{
			if (moveLeft.bPressed || moveLeft.bHeld)
			{
				return true;
			}
		}
		else
		{
			if (moveRight.bPressed || moveRight.bHeld)
			{
				return true;
			}
		}

		return false;
	}
}