#include "BackgroundObj.h"

namespace RB::Background
{
	BackgroundObj::BackgroundObj(std::string path, RB::Sprites::SpriteEnum spriteEnum, float_t percentage)
	{
		_renderSize = olc::vf2d{ 1152.0f, 720.0f };
		_position = olc::vf2d{ _renderSize.x * 0.5f * -1.0f, 0.0f };

		_spriteEnum = spriteEnum;
		_percentage = percentage;

		_spriteRenderer.LoadSprite(path, spriteEnum);
	}

	void BackgroundObj::Init()
	{

	}

	void BackgroundObj::OnUpdate()
	{
		_camControllerGetter.OnUpdate();

		if (_camControllerGetter.GetController() == nullptr)
		{
			return;
		}

		float_t offsetX = _position.x + (_camControllerGetter.GetController()->GetCamObj()->GetPosition().x * _percentage);

		_spriteRenderer.RenderSprite(_spriteEnum, _renderSize, olc::vf2d{ offsetX, _position.y }, olc::WHITE, RB::Sprites::PivotType::BOTTOM_LEFT);
	}

	void BackgroundObj::OnFixedUpdate()
	{

	}
}