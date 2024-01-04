#pragma once
#include "SpriteLoader.h"

namespace RB::Render
{
	class PlayerBoxRenderer
	{
	public:
		PlayerBoxRenderer() = default;
		~PlayerBoxRenderer() = default;

	public:
		void Init(RB::Sprites::SpriteLoader* spriteLoader);
		void OnUpdate();
		void OnFixedUpdate();

		void RenderPlayerBox(bool render);

	private:
		RB::Sprites::SpriteLoader* _spriteLoader = nullptr;
		bool _renderPlayerBox = true;
	};
}