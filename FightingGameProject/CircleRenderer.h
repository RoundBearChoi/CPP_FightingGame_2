#pragma once

#include "Vector2.h"

namespace RB::Render
{
	class CircleRenderer
	{
	public:
		CircleRenderer() = default;
		~CircleRenderer() = default;

		void Init();
		void OnFixedUpdate();
		void Render(int radius);

	public:
		void SetPos(RB::Vector2 pos);

	private:
		RB::Vector2 _pos = { 0.0f, 0.0f };
	};
}
