#pragma once

namespace RB::Updaters
{
	template <class T>
	class SkipFixedUpdates
	{
	public:
		void SetSkipFrames(unsigned int skipFrames)
		{
			_skipFrames = skipFrames;
		}

		void SetFunction(T* obj, void (T::*function)())
		{
			_obj = obj;
			_function = function;
		}

		void CallFunction()
		{
			if (_frameCount < _skipFrames)
			{
				//std::cout << "skipping frame" << std::endl;

				_frameCount++;
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