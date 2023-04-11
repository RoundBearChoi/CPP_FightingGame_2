#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "iController.h"
#include "iBoxRenderer.h"

namespace RB::Render
{
	class iBoxRenderController : public RB::Controllers::iController
	{
	public:
		virtual ~iBoxRenderController() {}

	public:
		virtual iBoxRenderer* GetBoxRenderer() = 0;
	};
}