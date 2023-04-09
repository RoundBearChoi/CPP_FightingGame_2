#pragma once

namespace RB::Updaters
{
	template <typename T>
	class SkipFrameUpdater
	{
	public:
		void SetTargetObj(T* targetObj);
		void SetMemberFunction(void (T::*func)());

		void callMemberFunction()
		{
			(myObject->*Func)();
		}

	private:
		int _skipFrames = 0;
		T* myObject = nullptr;
		void (T::*Func)() = nullptr;
	};

	template<typename T>
	void SkipFrameUpdater<T>::SetTargetObj(T* targetObj)
	{
		myObject = targetObj;
	}
	
	template<typename T>
	void SkipFrameUpdater<T>::SetMemberFunction(void(T::* func)())
	{
		Func = func;
	}
}