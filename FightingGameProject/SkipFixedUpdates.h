#pragma once

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
			_totalFrameCount++;

			if (_frameCount < _skipFrames)
			{
				_frameCount++;
			}
			else
			{
				_frameCount = 0;

				(_obj->*_function)();
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
		T* _obj = nullptr;
		void (T::* _function)() = nullptr;
	};
}