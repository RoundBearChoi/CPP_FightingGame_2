#pragma once
#include <cmath>

#include "iPlayerController.h"

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
		float_t _GetSqMagBetweenPlayers();
	};
}