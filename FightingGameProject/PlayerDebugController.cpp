#include "PlayerDebugController.h"

namespace RB::Render
{
	PlayerDebugController::PlayerDebugController()
	{
		SetHash(typeid(*this));

		PLAYER_DEBUG_CONTROLLER = this;
	}

	PlayerDebugController::~PlayerDebugController()
	{
		PLAYER_DEBUG_CONTROLLER = nullptr;
	}

	void PlayerDebugController::Init()
	{
		_spriteRenderer.Init();
		_spriteRenderer.LoadSprite("PNG files/DebugElements/x_white.png", RB::Sprites::SpriteEnum::x_white);
		_spriteRenderer.LoadSprite("PNG files/DebugElements/white_sq_tr80.png", RB::Sprites::SpriteEnum::white_sq_tr80);

		_lineRenderer.Init();

		_playerBoxRenderer.Init(&_spriteRenderer);
		_playerHurtBoxRenderer.Init(&_spriteRenderer);
		_playerPositionRenderer.Init(&_spriteRenderer, &_lineRenderer);
	}

	void PlayerDebugController::OnUpdate()
	{
		_playerBoxRenderer.OnUpdate();
		_playerHurtBoxRenderer.OnUpdate();
		_playerPositionRenderer.OnUpdate();
	}

	void PlayerDebugController::OnFixedUpdate()
	{
		_playerBoxRenderer.OnFixedUpdate();
		_playerHurtBoxRenderer.OnFixedUpdate();
		_playerPositionRenderer.OnFixedUpdate();
	}
}