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
		_spriteObj.LoadSprite("PNG files/DebugElements/x_white.png", RB::Sprites::SpriteEnum::x_white);
		_spriteObj.LoadSprite("PNG files/DebugElements/white_sq_tr80.png", RB::Sprites::SpriteEnum::white_sq_tr80);

		_playerBoxRenderer.Init(&_spriteObj);
		_playerHBoxRenderer.Init(&_spriteObj);
		_playerPositionRenderer.Init(&_spriteObj, &_lineRenderer);
		_playerInputRenderer.Init();
	}

	void PlayerDebugController::OnUpdate()
	{
		_playerBoxRenderer.OnUpdate();
		_playerHBoxRenderer.OnUpdate();
		_playerPositionRenderer.OnUpdate();
		_playerInputRenderer.OnUpdate();
	}

	void PlayerDebugController::OnFixedUpdate()
	{
		_playerBoxRenderer.OnFixedUpdate();
		_playerHBoxRenderer.OnFixedUpdate();
		_playerPositionRenderer.OnFixedUpdate();
		_playerInputRenderer.OnFixedUpdate();
	}
}