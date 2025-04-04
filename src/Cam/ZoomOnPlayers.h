#pragma once

#include "iCamController.h"

#include "../Vector2.h"
#include "../Ease.h"

#include "../Players/iPlayerController.h"

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