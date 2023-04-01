#pragma once
#include <cstdint>

namespace RB::Engine
{
	class Timer
	{
	private:
		float _targetInterval = 1.0f / 60.0f;

		//debug
		float _accumulatedTime = 0.0f;
		float _time = 0.0f;
		int32_t _updateCount = 0;
		int32_t _updateCountPerSec = 0;

	public:
		bool UpdateTime(float fElapsedTime)
		{
			_accumulatedTime += fElapsedTime;

			if (_time >= 1.0f)
			{
				_updateCountPerSec = _updateCount;
				_updateCount = 0;
				_time = 0.0f;
			}
			else
			{
				_time += fElapsedTime;
			}

			if (_accumulatedTime >= _targetInterval)
			{
				_accumulatedTime -= _targetInterval;
				_updateCount++;

				return true;
			}
			else
			{
				return false;
			}
		}

		void ShowFixedUpdateCount()
		{
			olc::Renderer::ptrPGE->DrawString({3, 3}, "FixedUpdate Count: " + std::to_string(_updateCountPerSec), olc::WHITE);
		}
	};
}