#pragma once
#include <cmath>

#include "iPlayerController.h"
#include "iCamController.h"

namespace RB::Cam
{
	class ZoomOnPlayers
	{
	public:
		ZoomOnPlayers() = default;
		~ZoomOnPlayers() = default;

	public:
		void Init();
		void OnFixedUpdate();

	private:
		float_t _GetMagSqBetweenPlayers();
		void _AutoZoom(float_t playerDistSq);

	private:
		float_t _maxDist = 1500.0f;
		float_t _minZoomOut = 0.5f;
		float_t _maxZoomIn = 1.25f;
	};
}