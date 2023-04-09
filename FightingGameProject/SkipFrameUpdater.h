#pragma once

namespace RB::Updaters
{
	template <typename T, void (T::*Func)()>
	class SkipFrameUpdater
	{
	public:
		T* myObject;

		//constructor
		SkipFrameUpdater(T* obj) : myObject(obj)
		{

		}

		void callMemberFunction()
		{
			(myObject->*Func)();
		}

	private:
		int _skipFrames = 0;
	};
}