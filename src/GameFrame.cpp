#include "GameFrame.h"

namespace RB
{
	InfInt gFrame = 0;

	unsigned int gameFrameCount = 0;
	//unsigned int maxGameFrameCount = 0;

	void AddGameFrame()
	{
		gFrame++;
		
		//if (maxGameFrameCount == 0)
		//{
		//	maxGameFrameCount = std::numeric_limits<unsigned int>::max();
		//}

		//gameFrameCount++;
	}
}
