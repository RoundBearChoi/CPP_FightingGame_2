#pragma once

#include "olcPixelGameEngine.h"

namespace RB::Render
{
	class CircleRenderer
	{
	public:
		CircleRenderer() = default;
		~CircleRenderer() = default;

		void Init();
		void OnFixedUpdate();
		void Render();

	public:
		void SetPos(olc::vf2d pos);

	private:
		olc::vf2d _pos = { 0.0f, 0.0f };
	};
}