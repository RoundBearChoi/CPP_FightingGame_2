#pragma once
#include "olcPixelGameEngine.h"
#include "AABB.h"

#include "SpriteRenderer.h"
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
		void Init(SpriteRenderer* spriteRenderer, LineRenderer* lineRenderer);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void RenderPosition(RB::Players::PlayerID playerID);
		void RenderBottomLeft(RB::Players::PlayerID playerID);
		void RenderAirMomentum(RB::Players::PlayerID playerID);

	private:
		SpriteRenderer* _spriteRenderer = nullptr;
		LineRenderer* _lineRenderer = nullptr;
	};
}
