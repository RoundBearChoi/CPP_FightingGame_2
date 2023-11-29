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
		_sprites.LoadSprite("PNG files/DebugElements/x_white.png", RB::Sprites::SpriteEnum::x_white);
		_sprites.LoadSprite("PNG files/DebugElements/white_sq_tr80.png", RB::Sprites::SpriteEnum::white_sq_tr80);

		_sprites.LoadSprite("PNG files/InputIcons/arrow_up.png", RB::Sprites::SpriteEnum::input_arrow_up);
		_sprites.LoadSprite("PNG files/InputIcons/arrow_down.png", RB::Sprites::SpriteEnum::input_arrow_down);
		_sprites.LoadSprite("PNG files/InputIcons/arrow_left.png", RB::Sprites::SpriteEnum::input_arrow_left);
		_sprites.LoadSprite("PNG files/InputIcons/arrow_right.png", RB::Sprites::SpriteEnum::input_arrow_right);
		_sprites.LoadSprite("PNG files/InputIcons/weak_punch.png", RB::Sprites::SpriteEnum::input_weak_punch);
		_sprites.LoadSprite("PNG files/InputIcons/weak_kick.png", RB::Sprites::SpriteEnum::input_weak_kick);


		_playerBoxRenderer.Init(&_sprites);
		_playerHBoxRenderer.Init(&_sprites);
		_playerPositionRenderer.Init(&_sprites, &_lineRenderer);
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