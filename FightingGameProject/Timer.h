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
		float _fullSecondCount = 0.0f;
		int32_t _fixedUpdateCount = 0;
		int32_t _fixedUpdateCountPerSec = 0;

	public:
		void FixedUpdate()
		{

		}

		bool UpdateTime(float fElapsedTime)
		{
			ShowFixedUpdateCount();

			_accumulatedTime += fElapsedTime;

			if (_fullSecondCount >= 1.0f)
			{
				_fixedUpdateCountPerSec = _fixedUpdateCount;
				_fixedUpdateCount = 0;
				_fullSecondCount = 0.0f;
			}
			else
			{
				_fullSecondCount += fElapsedTime;
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