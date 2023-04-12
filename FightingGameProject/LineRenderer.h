#pragma once
#include <iostream>
#include "iLineRenderer.h"

namespace RB::Render
{
	class LineRenderer : public iLineRenderer
	{
	public:
		LineRenderer();
		~LineRenderer() override;

	public:
		void Init() override;
	};
}