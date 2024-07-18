#pragma once

#include "AABB.h"
#include "Vector2.h"
#include "PlayerID.h"
#include "SpriteContainer.h"
#include "LineRenderer.h"

#include "iPlayerController.h"

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
