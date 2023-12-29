#pragma once
#include "Sprites.h"

#include "iPlayerController.h"

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

	private:
		RB::Sprites::SpriteLoader* _spriteLoader = nullptr;
	};
}