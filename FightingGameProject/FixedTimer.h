#pragma once
#include <cstdint>
#include "Time.h"

namespace RB::Frames
{
	class FixedTimer
	{
	private:
		float _targetInterval = 1.0f / 60.0f;

		//debug
		float _accumulatedTime = 0.0f;
		float _fullSecondCount = 0.0f;
		int32_t _fixedUpdateCount = 0;
		int32_t _fixedUpdateCountPerSec = 0;

	public:
		bool DoFixedUpdate()
		{
			ShowFixedUpdateCount();

			float elapsed = Time::GetDeltaTime();

			_accumulatedTime += elapsed;

			if (_fullSecondCount >= 1.0f)
			{
				_fixedUpdateCountPerSec = _fixedUpdateCount;
				_fixedUpdateCount = 0;
				_fullSecondCount = 0.0f;
			}
			else
			{
				_fullSecondCount += elapsed;
			}

			if (_accumulatedTime >= _targetInterval)
			{
				_accumulatedTime -= _targetInterval;
				_fixedUpdateCount++;

				return true;
			}
			else
			{
				return false;
			}
		}

		void ShowFixedUpdateCount()
		{
			olc::Renderer::ptrPGE->DrawString({3, 3}, "FixedUpdate Count: " + std::to_string(_fixedUpdateCountPerSec), olc::WHITE);
		}
	};
}