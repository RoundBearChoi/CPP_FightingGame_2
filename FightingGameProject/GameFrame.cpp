#include "GameFrame.h"

namespace RB
{
	size_t gameFrameCount = 0;
	size_t gameFrameLoopCount = 0;
	size_t maxGameFrameCount = 0;

	void AddGameFrame()
	{
		gameFrameCount++;

		if (maxGameFrameCount == 0)
		{
			maxGameFrameCount = std::numeric_limits<size_t>::max();
		}

		if (gameFrameCount == maxGameFrameCount)
		{
			gameFrameCount = 0;
			gameFrameLoopCount++;
		}
	}
}