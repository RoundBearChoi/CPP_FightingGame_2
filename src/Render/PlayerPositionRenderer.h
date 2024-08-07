#pragma once

#include "LineRenderer.h"

#include "../Collisions/AABB.h"
#include "../Vector2.h"
#include "../Players/PlayerID.h"
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
		void Init(RB::Sprites::SpriteContainer* spriteContainer, LineRenderer* lineRenderer);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void RenderPosition(RB::Players::PlayerID playerID);
		void RenderBottomLeft(RB::Players::PlayerID playerID);

	private:
		RB::Sprites::SpriteContainer* _spriteContainer = nullptr;
		LineRenderer* _lineRenderer = nullptr;
	};
}
