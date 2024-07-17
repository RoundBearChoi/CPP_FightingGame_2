#include "GameFrame.h"

#include <limits>

namespace RB
{
	unsigned int gameFrameCount = 0;
	unsigned int maxGameFrameCount = 0;

	void AddGameFrame()
	{
		if (maxGameFrameCount == 0)
		{
			maxGameFrameCount = std::numeric_limits<unsigned int>::max();
		}

		gameFrameCount++;
	}
}
