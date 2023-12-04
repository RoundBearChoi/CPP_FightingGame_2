#include "GeneralHitStopController.h"

namespace RB::Collisions
{
	void GeneralHitStopController::Init()
	{

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

	void GeneralHitStopController::AddSkipFrames(uint32_t frames)
	{
		_skipFrames += frames;
	}
}