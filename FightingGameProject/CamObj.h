#pragma once
#include "olcPixelGameEngine.h"
#include "iCamObj.h"

namespace RB::Cam
{
	class CamObj : public iCamObj
	{
	public:
		CamObj() = default;
		~CamObj() = default;

		olc::vf2d GetPosition() override;
		void SetPosition(olc::vf2d pos) override;
		void SetXPosition(float x) override;
		void SetYPosition(float y) override;
		olc::vf2d GetRelativePosition(olc::vf2d pos) override;
		float GetZoom() override;
		void SetZoom(float zoom) override;

		void Init();
		void ManualUpdate();
		void ManualFixedUpdate();

	private:
		olc::vf2d _camPosition = { 0.0f, 0.0f };
		float _displayHalfWidth = 0.0f;
		float _displayHalfHeight = 0.0f;
		float _zoom = 1.0f;
		float _zoomSpeed = 0.6f;
		float _moveSpeed = 3.0f;
		bool _moveLeft = false;
		bool _moveRight = false;
		bool _moveUp = false;
		bool _moveDown = false;
	};
}