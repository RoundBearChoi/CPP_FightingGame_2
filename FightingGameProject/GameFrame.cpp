#include "GameFrame.h"

#include <iostream>

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
			maxGameFrameCount = std::numeric_limits<unsigned int>::max();
		}

		if (gameFrameCount == maxGameFrameCount)
		{
			gameFrameCount = 0;
			gameFrameLoopCount++;
		}
	}
}