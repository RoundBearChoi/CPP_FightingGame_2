#include "Time.h"

namespace RB
{
	float Time::_deltaTime;
	//float Time::_fixedDeltaTime;

	void Time::SetDeltaTime(float delta)
	{
		_deltaTime = delta;
	}

	//void Time::AddFixedDeltaTime()
	//{
	//	_fixedDeltaTime += _deltaTime;
	//}

	//void Time::ResetFixedDeltaTime()
	//{
	//	_fixedDeltaTime = 0.0f;
	//}

	float Time::GetDeltaTime()
	{
		return _deltaTime;
	}

	//float Time::GetFixedDeltaTime()
	//{
	//	return _fixedDeltaTime;
	//}
}