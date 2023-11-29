#pragma once
#include <iostream>

size_t totalGameFrameCount = 0;
size_t maxGameFrameLoopCount = 0;
size_t maxGameFrameCount = 0;

void AddGameFrame()
{
	totalGameFrameCount++;

	if (maxGameFrameCount == 0)
	{
		maxGameFrameCount = std::numeric_limits<size_t>::max();	
	}

	if (totalGameFrameCount == maxGameFrameCount)
	{
		totalGameFrameCount = 0;
		maxGameFrameLoopCount++;
	}
}