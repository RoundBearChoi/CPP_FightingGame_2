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

		void SetTargetObj(T* targetObj)
		{
			_targetObj = targetObj;
		}

		void SetTargetFunction(void (T::*targetFunction)())
		{
			_targetFunction = targetFunction;
		}

		void CallTargetFunction()
		{
			(_targetObj->*_targetFunction)();
		}

	private:
		int _skipFrames = 0;
		T* _targetObj = nullptr;
		void (T::* _targetFunction)() = nullptr;
	};
}