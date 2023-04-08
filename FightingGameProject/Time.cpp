#include "Time.h"

namespace RB::Frames
{
	float Time::_deltaTime;

	void Time::SetDeltaTime(float delta)
	{
		_deltaTime = delta;
	}

	float Time::GetDeltaTime()
	{
		return _deltaTime;
	}
}