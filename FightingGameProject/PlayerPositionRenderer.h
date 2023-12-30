#pragma once

#include "PlayerID.h"
#include "SpriteLoader.h"
#include "LineRenderer.h"

namespace RB::Render
{
	class PlayerPositionRenderer
	{
	public:
		PlayerPositionRenderer() = default;
		~PlayerPositionRenderer() = default;

	public:
		void Init(RB::Sprites::SpriteLoader* spriteLoader, LineRenderer* lineRenderer);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void RenderPosition(RB::Players::PlayerID playerID);
		void RenderBottomLeft(RB::Players::PlayerID playerID);

	private:
		RB::Sprites::SpriteLoader* _spriteLoader = nullptr;
		LineRenderer* _lineRenderer = nullptr;
	};
}