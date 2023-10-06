#pragma once
#include <cstdint>

namespace RB::Updaters
{
	template <class T>
	class SkipFixedUpdates
	{
	public:
		SkipFixedUpdates() = default;
		~SkipFixedUpdates() = default;

	public:
		void SetSkipFrames(uint32_t skipFrames)
		{
			_skipFrames = skipFrames;
		}

		void SetFunction(T* obj, void (T::*function)())
		{
			_obj = obj;
			_function = function;
		}

		void OnFixedUpdate()
		{
			if (_frameCount < _skipFrames)
			{
				_frameCount++;
				_totalFrameCount++;
			}
			else
			{
				_frameCount = 0;

				(_obj->*_function)();
			}
		}

		size_t GetTotalFixedUpdateCount()
		{
			return _totalFrameCount;
		}

	private:
		uint32_t _skipFrames = 0;
		size_t _frameCount = 0;
		size_t _totalFrameCount = 0;
		T* _obj = nullptr;
		void (T::* _function)() = nullptr;
	};
}