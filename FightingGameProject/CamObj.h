#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "iCam.h"
#include "Time.h"

#include "ControllerGetter.h"
#include "InputController.h"

namespace RB::Cam
{
	class CamObj : public iCam
	{
	public:
		CamObj() = default;
		~CamObj() = default;

	public:
		olc::vi2d GetPosition() override;
		olc::vi2d GetRelativePosition(olc::vi2d pos) override;

	public:
		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	private:
		olc::vi2d _camPosition = { -427, -427 };
		float_t _zoomAmount = 1.0f;
		int32_t _moveSpeed = 2;
		bool _moveLeft = false;
		bool _moveRight = false;
		bool _moveUp = false;
		bool _moveDown = false;

	private:
		RB::Controllers::ControllerGetter<RB::Input::InputController> _getter_inputController;
	};
}