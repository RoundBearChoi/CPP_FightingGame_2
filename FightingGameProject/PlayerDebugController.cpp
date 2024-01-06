#include "PlayerDebugController.h"

namespace RB::Render
{
	void PlayerDebugController::Init()
	{
		_spriteLoader.LoadSprite("PNG files/DebugElements/x_white.png", RB::Sprites::SpriteType::x_white);
		_spriteLoader.LoadSprite("PNG files/DebugElements/white_sq_tr80.png", RB::Sprites::SpriteType::white_sq_tr80);

		_spriteLoader.LoadSprite("PNG files/InputIcons/arrow_up.png", RB::Sprites::SpriteType::input_arrow_up);
		_spriteLoader.LoadSprite("PNG files/InputIcons/arrow_down.png", RB::Sprites::SpriteType::input_arrow_down);
		_spriteLoader.LoadSprite("PNG files/InputIcons/arrow_left.png", RB::Sprites::SpriteType::input_arrow_left);
		_spriteLoader.LoadSprite("PNG files/InputIcons/arrow_right.png", RB::Sprites::SpriteType::input_arrow_right);

		_spriteLoader.LoadSprite("PNG files/InputIcons/arrow_up_left.png", RB::Sprites::SpriteType::input_arrow_up_left);
		_spriteLoader.LoadSprite("PNG files/InputIcons/arrow_up_right.png", RB::Sprites::SpriteType::input_arrow_up_right);
		_spriteLoader.LoadSprite("PNG files/InputIcons/arrow_down_left.png", RB::Sprites::SpriteType::input_arrow_down_left);
		_spriteLoader.LoadSprite("PNG files/InputIcons/arrow_down_right.png", RB::Sprites::SpriteType::input_arrow_down_right);

		_spriteLoader.LoadSprite("PNG files/InputIcons/weak_punch.png", RB::Sprites::SpriteType::input_weak_punch);
		_spriteLoader.LoadSprite("PNG files/InputIcons/weak_kick.png", RB::Sprites::SpriteType::input_weak_kick);

		_playerBoxRenderer.Init(&_spriteLoader);
		_playerHBoxRenderer.Init(&_spriteLoader);
		_playerPositionRenderer.Init(&_spriteLoader, &_lineRenderer);
		_playerInputRenderer.Init(&_spriteLoader);
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

	void PlayerDebugController::RenderPlayerBox(bool render)
	{
		_playerBoxRenderer.RenderPlayerBox(render);
	}
}