#include "SkipFrameUpdater.h"

namespace RB::Updaters
{
	template<typename T, void(T::* Func)()>
	SkipFrameUpdater<T, Func>::SkipFrameUpdater(int skipFrames, void(*some)())
	{

	}

	template<typename T, void(T::* Func)()>
	SkipFrameUpdater<T, Func>::~SkipFrameUpdater()
	{

	}
}