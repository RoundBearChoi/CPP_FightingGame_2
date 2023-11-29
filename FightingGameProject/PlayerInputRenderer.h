#pragma once

#include "Sprites.h"

namespace RB::Render
{
	class PlayerInputRenderer
	{
	public:
		PlayerInputRenderer() = default;
		~PlayerInputRenderer() = default;

		void Init(Sprites* sprites);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		Sprites* _sprites = nullptr;
	};
}