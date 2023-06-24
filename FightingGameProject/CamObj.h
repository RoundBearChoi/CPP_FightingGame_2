#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "Time.h"

#include "iCamObj.h"
#include "InputController.h"

namespace RB::Cam
{
	class CamObj : public iCamObj
	{
	public:
		CamObj() = default;
		~CamObj() = default;

		olc::vf2d GetPosition() override;
		olc::vf2d GetRelativePosition(olc::vf2d pos) override;
		float_t GetZoom() override;

		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	private:
		olc::vf2d _camPosition = { -427.0f, -427.0f };
		float_t _zoom = 1.0f;
		float_t _zoomSpeed = 0.6f;
		float_t _moveSpeed = 3.0f;
		bool _moveLeft = false;
		bool _moveRight = false;
		bool _moveUp = false;
		bool _moveDown = false;
	};
}