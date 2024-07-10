#include "BackgroundObj.h"

#include "iCamController.h"

namespace RB::Background
{
	BackgroundObj::BackgroundObj(std::string path, RB::Sprites::SpriteType spriteType, float percentage)
	{
		//_renderSize = olc::vf2d{ 1152.0f, 736.0f };
		_imageWidth = 288;
		_imageHeight = 184;
		_renderScale = 4.0f;
		_position = olc::vf2d{ _imageWidth * _renderScale * 2.0f * -1.0f, 16.0f };

		_spriteType = spriteType;
		_percentage = percentage;

		_spriteContainer.LoadSprite(path, spriteType);
	}

	void BackgroundObj::Init()
	{

	}

	void BackgroundObj::OnUpdate()
	{
		if (RB::Cam::iCamController::Get() == nullptr)
		{
			return;
		}

		float offsetX = _position.x + (RB::Cam::iCamController::Get()->GetCamObj()->GetPosition().x * _percentage);

		//background horizontal tile
		for (int i = 0; i < 4; i++)
		{
			_spriteContainer.RenderSprite(_spriteType, _imageWidth * _renderScale, _imageHeight * _renderScale, olc::vf2d{ offsetX + (_imageWidth * _renderScale * i), _position.y }, olc::WHITE, RB::Sprites::PivotType::BOTTOM_LEFT, true);
		}
	}

	void BackgroundObj::OnFixedUpdate()
	{

	}
}
