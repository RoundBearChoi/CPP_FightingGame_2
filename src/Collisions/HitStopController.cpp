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

	bool HitStopController::SkipFrame()
	{
		if (_skipFrames > 0)
		{
			_skipFrames--;

			return true;
		}

		if (_skipFrames < 0)
		{
			_skipFrames = 0;
		}

		return false;
	}

	void HitStopController::AddSkipFrames(int frames)
	{
		if (frames <= 0)
		{
			return;
		}
		else
		{
			_skipFrames += frames;
		}
	}
}