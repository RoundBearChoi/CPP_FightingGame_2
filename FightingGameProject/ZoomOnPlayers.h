#pragma once
#include "Ease.h"

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
		float _GetMagSqBetweenPlayers();
		void _AutoZoom(float playerDistSq);

	private:
		float _maxDist = 1600.0f;
		float _minZoomOut = 0.5f;
		float _maxZoomIn = 1.25f;
	};
}