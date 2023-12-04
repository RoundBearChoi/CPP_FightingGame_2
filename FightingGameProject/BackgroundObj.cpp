#include "BackgroundObj.h"

namespace RB::Background
{
	BackgroundObj::BackgroundObj(std::string path, RB::Sprites::SpriteEnum spriteEnum, float_t percentage)
	{
		_renderSize = olc::vf2d{ 1152.0f, 736.0f };
		_position = olc::vf2d{ _renderSize.x * 2.0f * -1.0f, 16.0f };

		_spriteEnum = spriteEnum;
		_percentage = percentage;

		_sprites.LoadSprite(path, spriteEnum);
	}

	void BackgroundObj::Init()
	{

	}

	void BackgroundObj::OnUpdate()
	{
		if (RB::Cam::iCamController::instance == nullptr)
		{
			return;
		}

		float_t offsetX = _position.x + (RB::Cam::iCamController::instance->GetCamObj()->GetPosition().x * _percentage);

		//background horizontal tile
		for (int32_t i = 0; i < 4; i++)
		{
			_sprites.RenderSprite(_spriteEnum, _renderSize, olc::vf2d{ offsetX + (_renderSize.x * i), _position.y }, olc::WHITE, RB::Sprites::PivotType::BOTTOM_LEFT);
		}
	}

	void BackgroundObj::OnFixedUpdate()
	{

	}
}