#pragma once
#include "ControllerBase.h"
#include "SpriteEnum.h"
#include "SpriteEnumString.h"

namespace RB::Sprites
{
	class iSpriteDataController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual const std::string& GetString(SpriteEnum spriteEnum) = 0;
	};

	extern iSpriteDataController* SPRITE_DATA_CONTROLLER;
}