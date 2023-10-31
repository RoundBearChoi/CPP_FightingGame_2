#pragma once
#include <cmath>
#include "iCamObj.h"
#include "iPlayerController.h"
#include "Ease.h"

namespace RB::Cam
{
	class FollowPlayers
	{
	public:
		FollowPlayers() = default;
		~FollowPlayers() = default;

		void Init(iCamObj* cam);

		void OnUpdate();
		void OnFixedUpdate();

	private:
		iCamObj* _camObj = nullptr;
		float_t _maxDist = 0.0f;
	};
}