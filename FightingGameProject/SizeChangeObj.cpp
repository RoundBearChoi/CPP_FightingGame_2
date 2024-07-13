#include "SizeChangeObj.h"

#include <iostream>
#include <string>

namespace RB::Render
{
	SizeChangeObj::SizeChangeObj(int totalFrames, SizeChangeType sizeChangeType, float totalSizeChangeMultiplier)
	{
		_totalFrames = totalFrames;
		_sizeChangeType = sizeChangeType;
		_totalSizeChangeMultiplier = totalSizeChangeMultiplier;
	}

	void SizeChangeObj::OnFixedUpdate()
	{
		//std::cout << "processing sizeChange.. " << std::to_string(_processedFrames) << std::endl;

		_processedFrames++;
	}

	bool SizeChangeObj::DoDelete()
	{
		if (_processedFrames >= _totalFrames)
		{
			//std::cout << "deleting.." << std::endl;
			return true;
		}
		else
		{
			return false;
		}
	}
}
