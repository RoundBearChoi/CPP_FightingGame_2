#pragma once

#include "olcPixelGameEngine.h"

#include "Vector2.h"
#include "GameSettings.h"
#include "LineRenderer.h"
#include "SpriteContainer.h"
#include "RenderLayerType.h"
#include "PlayerInputRenderer.h"
#include "PlayerPositionRenderer.h"
#include "PlayerBoxRenderer.h"
#include "PlayerHBoxRenderer.h"

#include "Render/iPlayerDebugController.h"
#include "iCamController.h"

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
		void _RenderBodyParts(RB::Players::PlayerID id);

	private:
		RB::Sprites::SpriteContainer _spriteContainer;
		RB::Render::LineRenderer _lineRenderer;

	private:
		PlayerBoxRenderer _playerBoxRenderer;
		PlayerHBoxRenderer _playerHBoxRenderer;
		PlayerPositionRenderer _playerPositionRenderer;
		PlayerInputRenderer _playerInputRenderer;
	};
}
