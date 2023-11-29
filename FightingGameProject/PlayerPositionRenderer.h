#pragma once
#include "olcPixelGameEngine.h"
#include "AABB.h"

#include "Sprites.h"
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
		void Init(Sprites* spriteRenderer, LineRenderer* lineRenderer);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void RenderPosition(RB::Players::PlayerID playerID);
		void RenderBottomLeft(RB::Players::PlayerID playerID);

	private:
		Sprites* _spriteObj = nullptr;
		LineRenderer* _lineRenderer = nullptr;
	};
}
