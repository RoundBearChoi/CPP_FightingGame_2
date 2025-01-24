#pragma once

#include "Loaded_HB_Data.h"

#include "../Controllers/ControllerBase.h"

namespace RB::HBox
{
	#define GET_ATTACK_BOX_DATA_CONTROLLER static_cast<HBox::iAttackBoxDataController*>(Controllers::GetController(Controllers::ControllerType::ATTACK_BOX_DATA_CONTROLLER))

	class iAttackBoxDataController : public Controllers::ControllerBase
	{
	public:
		virtual Loaded_HB_Data* GetData(RB::Sprites::SpriteType spriteType) = 0;
		virtual Loaded_HB_Data* CreateData(RB::Sprites::SpriteType spriteType) = 0;
		virtual std::string GetPath(RB::Sprites::SpriteType spriteType) = 0;
	};
}