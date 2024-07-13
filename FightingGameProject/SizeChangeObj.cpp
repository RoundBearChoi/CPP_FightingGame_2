#include "SizeChangeObj.h"

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


		_processedFrames++;
	}

	bool SizeChangeObj::DoDelete()
	{
		if (_processedFrames >= _totalFrames)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
