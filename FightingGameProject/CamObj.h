#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "Time.h"
#include "DisplaySize.h"

#include "iCamObj.h"
#include "iInputController.h"

namespace RB::Cam
{
	class CamObj : public iCamObj
	{
	public:
		CamObj() = default;
		~CamObj() = default;

		olc::vf2d GetPosition() override;
		void SetPosition(olc::vf2d pos) override;
		void SetXPosition(float_t x) override;
		void SetYPosition(float_t y) override;
		olc::vf2d GetRelativePosition(olc::vf2d pos) override;
		float_t GetZoom() override;
		void SetZoom(float_t zoom) override;

		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	private:
		olc::vf2d _camPosition = { 0.0f, 0.0f };
		float_t _displayHalfWidth = 0.0f;
		float_t _displayHalfHeight = 0.0f;
		float_t _zoom = 1.0f;
		float_t _zoomSpeed = 0.6f;
		float_t _moveSpeed = 3.0f;
		bool _moveLeft = false;
		bool _moveRight = false;
		bool _moveUp = false;
		bool _moveDown = false;
	};
}