#pragma once
#include <vector>
#include "olcPixelGameEngine.h"
#include "GameplayControllers.h"
#include "iPlayerDebugController.h"
#include "iPlayer.h"
#include "PlayerID.h"
#include "PivotType.h"
#include "AABB.h"
#include "iSpriteRenderer.h"
#include "SpriteRenderer.h"
#include "iLineRenderer.h"
#include "LineRenderer.h"

namespace RB::PlayerDebug
{
	class PlayerDebugController : public iPlayerDebugController
	{
	public:
		PlayerDebugController();
		~PlayerDebugController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		void DrawPlayerPosition(RB::Players::iPlayer* player);
		void DrawPlayerBox(RB::Players::iPlayer* player);
		void DrawPlayerBottomLeft(RB::Players::iPlayer* player);
		void DrawPlayerAirMomentum(RB::Players::iPlayer* player);

	private:
		std::vector<RB::Players::iPlayer*> _vecPlayers;

	private:
		RB::Render::iSpriteRenderer* _spriteRenderer = nullptr;
		RB::Render::iLineRenderer* _lineRenderer = nullptr;
	};
}