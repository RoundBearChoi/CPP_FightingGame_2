#include "GameFrame.h"

namespace RB
{
	unsigned int gameFrameCount = 0;
	unsigned int gameFrameLoopCount = 0;
	unsigned int maxGameFrameCount = 0;

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