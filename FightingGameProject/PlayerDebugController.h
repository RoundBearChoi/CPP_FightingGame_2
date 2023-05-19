#pragma once
#include "ControllerBase.h"

#include "SpriteRenderer.h"
#include "LineRenderer.h"

#include "PlayerColliderBoxRenderer.h"
#include "PlayerPositionRenderer.h"

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

	private:
		RB::Render::SpriteRenderer _spriteRenderer;
		RB::Render::LineRenderer _lineRenderer;

	private:
		PlayerColliderBoxRenderer _playerColliderBoxRenderer;
		PlayerPositionRenderer _playerPositionRenderer;
	};
}