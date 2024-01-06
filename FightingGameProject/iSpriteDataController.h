#pragma once
#include <string>
#include "ControllerT.h"
#include "SpriteType.h"

namespace RB::Sprites
{
	class iSpriteDataController : public RB::Controllers::ControllerT<iSpriteDataController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual const std::string& GetString(SpriteType spriteType) = 0;
	};
}