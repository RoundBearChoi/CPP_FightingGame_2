#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "iController.h"
#include "iSpriteRenderer.h"

namespace RB::Render
{
	class iBoxRenderController : public RB::Controllers::iController
	{
	public:
		virtual ~iBoxRenderController() {}

	public:
		virtual iSpriteRenderer* GetBoxRenderer() = 0;
	};
}