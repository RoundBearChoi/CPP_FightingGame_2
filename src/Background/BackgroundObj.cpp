#include "BackgroundObj.h"

namespace RB::Background
{
	BackgroundObj::BackgroundObj(std::string path, Sprites::SPRITE_TYPE spriteType, float percentage)
	{
		_imageWidth = 288;
		_imageHeight = 184;
		_renderScale = 4.0f;
		_position = { _imageWidth * _renderScale * 2.0f * -1.0f, 16.0f };

		_spriteType = spriteType;
		_percentage = percentage;

		_spriteContainer.LoadSprite(path, spriteType);
	}

	void BackgroundObj::Init()
	{

	}

	void BackgroundObj::OnUpdate()
	{
		auto camController = GET_CAM_CONTROLLER;

		if (camController == nullptr)
		{
			return;
		}

		float offsetX = _position.x + (camController->GetCamObj()->GetPosition().x * _percentage);

		//background horizontal tile
		for (int i = 0; i < 4; i++)
		{
			_spriteContainer.RenderSprite(
				_spriteType,
				_imageWidth * _renderScale,
				_imageHeight * _renderScale,
				Vector2{ offsetX + (_imageWidth * _renderScale * i), _position.y },
				olc::WHITE,
				Sprites::PivotType::BOTTOM_LEFT,
				true);
		}
	}

	void BackgroundObj::OnFixedUpdate()
	{

	}
}
