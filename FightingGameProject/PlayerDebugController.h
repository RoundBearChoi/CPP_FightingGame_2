#pragma once

#include "SpriteObj.h"
#include "LineRenderer.h"

#include "PlayerHBoxRenderer.h"
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
		RB::Render::SpriteObj _spriteObj;
		RB::Render::LineRenderer _lineRenderer;

	private:
		PlayerBoxRenderer _playerBoxRenderer;
		PlayerHBoxRenderer _playerHBoxRenderer;
		PlayerPositionRenderer _playerPositionRenderer;
	};
}