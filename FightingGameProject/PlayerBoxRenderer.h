#pragma once
#include "SpriteContainer.h"

namespace RB::Render
{
	class PlayerBoxRenderer
	{
	public:
		PlayerBoxRenderer() = default;
		~PlayerBoxRenderer() = default;

	public:
		void Init(RB::Sprites::SpriteContainer* spriteContainer);
		void OnUpdate();
		void OnFixedUpdate();

		void RenderPlayerBox(bool render);

	private:
		RB::Sprites::SpriteContainer* _spriteContainer = nullptr;
		bool _renderPlayerBox = true;
	};
}
