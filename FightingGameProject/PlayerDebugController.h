#pragma once
#include <vector>
#include "olcPixelGameEngine.h"
#include "PivotType.h"
#include "AABB.h"
#include "SpriteRenderer.h"
#include "LineRenderer.h"
#include "ControllerBase.h"

#include "ControllerGetter.h"
#include "PlayerController.h"

#include "PlayerColliderBoxRenderer.h"

namespace RB::Render
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
		void DrawPlayerBottomLeft(RB::Players::iPlayer* player);
		void DrawPlayerAirMomentum(RB::Players::iPlayer* player);

	private:
		RB::Render::SpriteRenderer _spriteRenderer;
		RB::Render::LineRenderer _lineRenderer;

	private:
		RB::Controllers::ControllerGetter<RB::Players::PlayerController> _getter_playerController;
		PlayerColliderBoxRenderer _playerColliderBoxRenderer;
	};
}