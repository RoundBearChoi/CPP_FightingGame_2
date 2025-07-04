#pragma once

#include "../olcPixelGameEngine.h"

#include "LineRenderer.h"
#include "PlayerBoxRenderer.h"
#include "PlayerHBoxRenderer.h"
#include "PlayerInputRenderer.h"
#include "PlayerPositionRenderer.h"
#include "Player_HP_Renderer.h"
#include "RenderLayerType.h"

#include "iPlayerDebugController.h"

#include "../Vector2.h"
#include "../GameSettings.h"

#include "../Sprites/SpriteContainer.h"

#include "../Cam/iCamController.h"

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
		void RenderPlayerHP(bool render) override;
		void RenderInput(bool render) override;

	private:
		void _RenderBodyParts(Players::PLAYER_TYPE id);

	private:
		Sprites::SpriteContainer _spriteContainer;
		Render::LineRenderer _lineRenderer;

	private:
		PlayerBoxRenderer _playerBoxRenderer;
		PlayerHBoxRenderer _playerHBoxRenderer;
		PlayerPositionRenderer _playerPositionRenderer;
		PlayerInputRenderer _playerInputRenderer;
		Player_HP_Renderer _player_HP_Renderer;
	};
}
