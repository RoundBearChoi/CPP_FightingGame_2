#pragma once

#include "LineRenderer.h"

#include "../Collisions/AABB.h"
#include "../Vector2.h"
#include "../Players/PlayerType.h"
#include "../Sprites/SpriteContainer.h"

#include "../Players/iPlayerController.h"

namespace RB::Render
{
	class PlayerPositionRenderer
	{
	public:
		PlayerPositionRenderer() = default;
		~PlayerPositionRenderer() = default;

	public:
		void Init(Sprites::SpriteContainer* spriteContainer, LineRenderer* lineRenderer);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void RenderPosition(RB::Players::PLAYER_TYPE playerID);
		void RenderBottomLeft(RB::Players::PLAYER_TYPE playerID);

	private:
		Sprites::SpriteContainer* _spriteContainer = nullptr;
		LineRenderer* _lineRenderer = nullptr;
	};
}
