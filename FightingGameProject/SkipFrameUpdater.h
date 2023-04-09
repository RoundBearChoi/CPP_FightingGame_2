#pragma once

namespace RB::Updaters
{
	template <typename T>
	class SkipFrameUpdater
	{
	public:
		T* myObject = nullptr;
		void (T::* Func)() = nullptr;

		void callMemberFunction()
		{
			(myObject->*Func)();
		}

	private:
		int _skipFrames = 0;
	};
}