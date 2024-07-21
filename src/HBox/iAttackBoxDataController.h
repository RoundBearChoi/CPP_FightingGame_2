#pragma once

#include "Loaded_HB_Data.h"

#include "../ControllerT.h"

namespace RB::HBox
{
	class iAttackBoxDataController : public RB::Controllers::ControllerT<iAttackBoxDataController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual Loaded_HB_Data* GetData(RB::Sprites::SpriteType spriteType) = 0;
		virtual Loaded_HB_Data* CreateData(RB::Sprites::SpriteType spriteType) = 0;
		virtual std::string GetPath(RB::Sprites::SpriteType spriteType) = 0;
	};
}
