#pragma once
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
	};
}