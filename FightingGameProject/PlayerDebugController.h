#pragma once
#include <vector>
#include "olcPixelGameEngine.h"
#include "GameplayControllers.h"
#include "iPlayer.h"
#include "PlayerID.h"
#include "PivotType.h"
#include "AABB.h"
#include "SpriteRenderer.h"
#include "LineRenderer.h"
#include "ControllerBase.h"
#include "CurrentControllers.h"
#include "PlayerController.h"

namespace RB::PlayerDebug
{
	class PlayerDebugController : public RB::Controllers::ControllerBase
	{
	public:
		PlayerDebugController();
		~PlayerDebugController() override {};

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
		RB::Render::SpriteRenderer _spriteRenderer;
		RB::Render::LineRenderer _lineRenderer;

	private:
		RB::Players::PlayerController* _playerController = nullptr;
	};
}