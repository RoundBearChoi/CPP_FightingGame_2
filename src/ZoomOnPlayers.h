#pragma once

#include "Vector2.h"
#include "Ease.h"

#include "iPlayerController.h"
#include "Cam/iCamController.h"

namespace RB::Cam
{
	class ZoomOnPlayers
	{
	public:
		ZoomOnPlayers();
		~ZoomOnPlayers() = default;

	public:
		void Init();
		void OnFixedUpdate();

	private:
		float _GetMagSqBetweenPlayers();
		void _AutoZoom(float playerDistSq);

	private:
		float _maxPlayerDist = 0.0f;
		float _maxZoomOut = 0.0f;
		float _maxZoomIn = 0.0f;
	};
}
