#include "GeneralHitStopController.h"

namespace RB::Collisions
{
	void GeneralHitStopController::Init()
	{
		INIT_CONTROLLER
	}

	void GeneralHitStopController::OnUpdate()
	{

	}

	void GeneralHitStopController::OnFixedUpdate()
	{

	}

	bool GeneralHitStopController::SkipFrame()
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

	void GeneralHitStopController::AddSkipFrames(int frames)
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