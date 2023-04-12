#pragma once
#include "iLineRenderer.h"

namespace RB::Render
{
	class LineRenderer : public iLineRenderer
	{
	public:
		LineRenderer();
		~LineRenderer() override;
	};
}