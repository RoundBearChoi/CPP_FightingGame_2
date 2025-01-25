#include "HitStopController.h"

namespace RB::Collisions
{
	void HitStopController::Init()
	{
		INIT_CONTROLLER
	}

	void HitStopController::OnUpdate()
	{

	}

	void HitStopController::OnFixedUpdate()
	{

	}

	bool HitStopController::StopFrame()
	{
		if (_stopFrames > 0)
		{
			_stopFrames--;

			return true;
		}

		if (_stopFrames < 0)
		{
			_stopFrames = 0;
		}

		return false;
	}

	void HitStopController::AddStopFrames(int frames)
	{
		if (frames <= 0)
		{
			return;
		}
		else
		{
			_stopFrames += frames;
		}
	}
}