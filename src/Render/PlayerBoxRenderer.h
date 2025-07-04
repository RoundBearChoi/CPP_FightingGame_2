#pragma once

#include "../olcPixelGameEngine.h"

#include "../Vector2.h"
#include "../Sprites/SpriteContainer.h"

#include "../Players/iPlayerController.h"

namespace RB::Render
{
	class PlayerBoxRenderer
	{
	public:
		PlayerBoxRenderer() = default;
		~PlayerBoxRenderer() = default;

	public:
		void Init(Sprites::SpriteContainer* spriteContainer);
		void OnUpdate();
		void OnFixedUpdate();

		void RenderPlayerBox(bool render);

	private:
		Sprites::SpriteContainer* _spriteContainer = nullptr;
		bool _renderPlayerBox = true;
	};
}
