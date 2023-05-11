#pragma once
#include "olcPixelGameEngine.h"
#include "ControllerBase.h"

namespace RB::Cam
{
	class iGameCamController : public RB::Controllers::ControllerBase
	{
	public:
		iGameCamController() = default;
		~iGameCamController() override {};
	};
}