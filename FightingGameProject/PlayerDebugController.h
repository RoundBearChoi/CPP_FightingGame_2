#pragma once

#include "PlayerInputRenderer.h"
#include "PlayerPositionRenderer.h"
#include "PlayerBoxRenderer.h"
#include "PlayerHBoxRenderer.h"
#include "LineRenderer.h"
#include "SpriteLoader.h"

#include "iPlayerDebugController.h"

namespace RB::Render
{
	class PlayerDebugController : public iPlayerDebugController
	{
	public:
		PlayerDebugController() = default;
		~PlayerDebugController() override {};

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		void RenderPlayerBox(bool render) override;

	private:
		RB::Sprites::SpriteLoader _spriteLoader;
		RB::Render::LineRenderer _lineRenderer;

	private:
		PlayerBoxRenderer _playerBoxRenderer;
		PlayerHBoxRenderer _playerHBoxRenderer;
		PlayerPositionRenderer _playerPositionRenderer;
		PlayerInputRenderer _playerInputRenderer;
	};
}