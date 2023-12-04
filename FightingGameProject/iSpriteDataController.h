#pragma once
#include "ControllerT.h"
#include "SpriteEnum.h"
#include "SpriteEnumString.h"

namespace RB::Sprites
{
	class iSpriteDataController : public RB::Controllers::ControllerT<iSpriteDataController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual const std::string& GetString(SpriteEnum spriteEnum) = 0;
	};
}