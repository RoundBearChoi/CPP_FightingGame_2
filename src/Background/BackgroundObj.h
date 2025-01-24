#pragma once

#include "../Vector2.h"
#include "../Sprites/SpriteType.h"
#include "../Sprites/SpriteContainer.h"

#include "../Cam/iCamController.h"

namespace RB::Background
{
	class BackgroundObj
	{
	public:
		BackgroundObj(std::string path, Sprites::SpriteType spriteType, float percentage);
		~BackgroundObj() = default;

		void Init();
		void OnUpdate();
		void OnFixedUpdate();

	private:
		float _percentage = 0.0f;
		Sprites::SpriteType _spriteType = Sprites::SpriteType::NONE;
		float _imageWidth = 0.0f;
		float _imageHeight = 0.0f;
		float _renderScale = 1.0f;
		Vector2 _position = { 0.0f, 0.0f };
		Sprites::SpriteContainer _spriteContainer;
	};
}