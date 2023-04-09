#pragma once

namespace RB::Updaters
{
	template <typename T>
	class SkipFrameUpdater
	{
	public:
		void SetTargetObj(T* targetObj)
		{
			myObject = targetObj;
		}

		void SetTargetFunction(void (T::*func)())
		{
			Func = func;
		}

		void CallTargetFunction()
		{
			(myObject->*Func)();
		}

	private:
		int _skipFrames = 0;
		T* myObject = nullptr;
		void (T::*Func)() = nullptr;
	};
}