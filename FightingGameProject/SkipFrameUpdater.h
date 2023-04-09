#pragma once

namespace RB::Updaters
{
	template <typename T>
	class SkipFrameUpdater
	{
	public:
		void SetSkipFrames(unsigned int skipFrames)
		{
			_skipFrames = skipFrames;
		}

		void SetObj(T* targetObj)
		{
			_obj = targetObj;
		}

		void SetFunction(void (T::*function)())
		{
			_function = function;
		}

		void CallFunction()
		{
			if (_frameCount < _skipFrames)
			{
				_frameCount++;

				//std::cout << "skipping frame" << std::endl;
			}
			else
			{
				//std::cout << "running func" << std::endl;

				_frameCount = 0;
				(_obj->*_function)();
			}
		}

	private:
		unsigned int _skipFrames = 0;
		unsigned int _frameCount = 0;
		T* _obj = nullptr;
		void (T::* _function)() = nullptr;
	};
}