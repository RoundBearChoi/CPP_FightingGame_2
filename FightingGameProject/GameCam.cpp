#include "GameCam.h"

namespace RB::Cam
{
	GameCam::GameCam()
	{

	}

	GameCam::~GameCam()
	{

	}

	olc::vi2d GameCam::GetPosition()
	{
		return _position;
	}

	void GameCam::Init()
	{

	}

	void GameCam::OnUpdate()
	{
		_moveUp = false;
		_moveDown = false;
		_moveLeft = false;
		_moveRight = false;

		olc::HWButton moveUp = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_UP);
		olc::HWButton moveDown = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_DOWN);

		olc::HWButton moveLeft = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_LEFT);
		olc::HWButton moveRight = RB::Controllers::GameplayControllers::INPUT_CONTROLLER->GetButton(RB::Players::PlayerID::NONE, RB::Input::PlayerInput::MOVE_CAM_RIGHT);

		if (moveUp.bHeld && moveDown.bHeld)
		{
			// do nothing
		}
		else if (moveUp.bHeld)
		{
			_moveUp = true;
		}
		else if (moveDown.bHeld)
		{
			_moveDown = true;
		}

		if (moveLeft.bHeld && moveRight.bHeld)
		{
			// do nothing
		}
		else if (moveLeft.bHeld)
		{
			_moveLeft = true;
		}
		else if (moveRight.bHeld)
		{
			_moveRight = true;
		}
	}

	void GameCam::OnFixedUpdate()
	{
		if (_moveUp)
		{
			_position.y -= _moveSpeed;
		}

		if (_moveDown)
		{
			_position.y += _moveSpeed;
		}

		if (_moveLeft)
		{
			_position.x -= _moveSpeed;
		}

		if (_moveRight)
		{
			_position.x += _moveSpeed;
		}
	}
}