#pragma once

namespace RB::Updaters
{
	template <typename T>
	class SkipFrameUpdater
	{
	public:
		void SetSkipFrames(int skipFrames)
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
			(_obj->*_function)();
		}

	private:
		int _skipFrames = 0;
		T* _obj = nullptr;
		void (T::* _function)() = nullptr;
	};
}