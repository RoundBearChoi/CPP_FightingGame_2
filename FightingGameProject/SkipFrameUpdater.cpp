#include "SkipFrameUpdater.h"

namespace RB::Updaters
{
	SkipFrameUpdater::SkipFrameUpdater(int skipFrames, void (*some)())
	{
		_skipFrames = skipFrames;
		sdfdsfdsfdsfsdfvv = some;
	}

	SkipFrameUpdater::~SkipFrameUpdater()
	{

	}

	void SkipFrameUpdater::OnUpdate()
	{

	}
}