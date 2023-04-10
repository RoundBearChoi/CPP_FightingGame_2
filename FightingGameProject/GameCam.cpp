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
			//_position.y -= 1;
			_moveUp = true;

			//std::cout << "cam pos: " << _position.x << ", " << _position.y << std::endl;
		}
		else if (moveDown.bHeld)
		{
			//_position.y += 1;
			_moveDown = true;

			//std::cout << "cam pos: " << _position.x << ", " << _position.y << std::endl;
		}

		if (moveLeft.bHeld && moveRight.bHeld)
		{
			// do nothing
		}
		else if (moveLeft.bHeld)
		{
			//_position.x -= 1;
			_moveLeft = true;

			//std::cout << "cam pos: " << _position.x << ", " << _position.y << std::endl;
		}
		else if (moveRight.bHeld)
		{
			//_position.x += 1;
			_moveRight = true;

			//std::cout << "cam pos: " << _position.x << ", " << _position.y << std::endl;
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