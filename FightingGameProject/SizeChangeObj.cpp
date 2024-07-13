#include "SizeChangeObj.h"

namespace RB::Render
{
	SizeChangeObj::SizeChangeObj(int totalFrames, SizeChangeType sizeChangeType)
	{
		_totalFrames = totalFrames;
		_sizeChangeType = sizeChangeType;
	}

	void SizeChangeObj::OnFixedUpdate()
	{

	}
}
