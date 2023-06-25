#pragma once

#include "SpriteRenderer.h"
#include "LineRenderer.h"

#include "PlayerHurtBoxRenderer.h"
#include "PlayerBoxRenderer.h"
#include "PlayerPositionRenderer.h"

#include "iPlayerDebugController.h"

namespace RB::Render
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

	private:
		RB::Render::SpriteRenderer _spriteRenderer;
		RB::Render::LineRenderer _lineRenderer;

	private:
		PlayerBoxRenderer _playerBoxRenderer;
		PlayerHurtBoxRenderer _playerHurtBoxRenderer;
		PlayerPositionRenderer _playerPositionRenderer;
	};
}