#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "iController.h"
#include "iSpriteRenderer.h"

namespace RB::Render
{
	class iDebugRenderController : public RB::Controllers::iController
	{
	public:
		virtual ~iDebugRenderController() {}

	public:
		virtual iSpriteRenderer* GetSpriteRenderer() = 0;
	};
}