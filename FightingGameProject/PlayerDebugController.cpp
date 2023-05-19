#include "PlayerDebugController.h"

namespace RB::Render
{
	PlayerDebugController::PlayerDebugController()
	{
		SetHash(typeid(*this));
	}

	void PlayerDebugController::Init()
	{
		_spriteRenderer.Init();
		_spriteRenderer.LoadSprite("PNG files/DebugElements/x_white.png", RB::Sprites::SpriteEnum::x_white);
		_spriteRenderer.LoadSprite("PNG files/DebugElements/white_sq_tr80.png", RB::Sprites::SpriteEnum::white_sq_tr80);

		_lineRenderer.Init();

		_playerColliderBoxRenderer.Init(&_spriteRenderer);
		_playerPositionRenderer.Init(&_spriteRenderer, &_lineRenderer);
	}

	void PlayerDebugController::OnUpdate()
	{
		_playerColliderBoxRenderer.OnUpdate();
		_playerPositionRenderer.OnUpdate();
	}

	void PlayerDebugController::OnFixedUpdate()
	{
		_playerColliderBoxRenderer.OnFixedUpdate();
		_playerPositionRenderer.OnFixedUpdate();
	}
}