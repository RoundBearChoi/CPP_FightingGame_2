#pragma once

#include "Lerp.h"
#include "Vector2.h"
#include "Ease.h"

#include "iCamObj.h"
#include "iPlayerController.h"

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
		float _maxDist = 0.0f;
	};
}
