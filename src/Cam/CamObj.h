#pragma once

#include "iCamObj.h"

#include "../Vector2.h"
#include "../DisplaySize.h"
#include "../Time.h"
#include "../Players/PlayerID.h"

#include "../iInputController.h"

namespace RB::Cam
{
	class CamObj : public iCamObj
	{
	public:
		CamObj() = default;
		~CamObj() = default;

		RB::Vector2 GetPosition() override;
		void SetPosition(RB::Vector2 pos) override;
		void SetXPosition(float x) override;
		void SetYPosition(float y) override;
		RB::Vector2 GetRelativePosition(RB::Vector2 pos) override;
		float GetZoom() override;
		void SetZoom(float zoom) override;

		void Init();
		void ManualUpdate();
		void ManualFixedUpdate();

	private:
		RB::Vector2 _camPosition = { 0.0f, 0.0f };
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
