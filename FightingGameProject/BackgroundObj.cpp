#include "BackgroundObj.h"

#include "iCamController.h"

namespace RB::Background
{
	BackgroundObj::BackgroundObj(std::string path, RB::Sprites::SpriteEnum spriteEnum, float percentage)
	{
		_renderSize = olc::vf2d{ 1152.0f, 736.0f };
		_position = olc::vf2d{ _renderSize.x * 2.0f * -1.0f, 16.0f };

		_spriteEnum = spriteEnum;
		_percentage = percentage;

		_spriteLoader.LoadSprite(path, spriteEnum);
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

		float offsetX = _position.x + (RB::Cam::iCamController::instance->GetCamObj()->GetPosition().x * _percentage);

		//background horizontal tile
		for (int i = 0; i < 4; i++)
		{
			_spriteLoader.RenderSprite(_spriteEnum, _renderSize, olc::vf2d{ offsetX + (_renderSize.x * i), _position.y }, olc::WHITE, RB::Sprites::PivotType::BOTTOM_LEFT);
		}
	}

	void BackgroundObj::OnFixedUpdate()
	{

	}
}