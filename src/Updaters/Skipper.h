#pragma once

#include <functional>

namespace RB::Updaters
{
	class Skipper
	{
	public:
		Skipper() = default;
		~Skipper() = default;

	public:
		void SetSkipFrames(unsigned int skipFrames)
		{
			_skipFrames = skipFrames;
		}

		void ClearSkipFrames()
		{
			_skipFrames = 0;
		}

		void SetFunction(std::function<void()> func)
		{
			_func = func;
		}

		bool DoFixedUpdate()
		{
			_totalFrameCount++;

			if (_frameCount < _skipFrames)
			{
				_frameCount++;

				return false;
			}
			else
			{
				_frameCount = 0;

				if (_func != nullptr)
				{
					_func();
				}

				return true;
			}
		}

		unsigned int GetTotalFixedUpdateCount()
		{
			return _totalFrameCount;
		}

	private:
		unsigned int _skipFrames = 0;
		unsigned int _frameCount = 0;
		unsigned int _totalFrameCount = 0;
		std::function<void()> _func = nullptr;
	};
}