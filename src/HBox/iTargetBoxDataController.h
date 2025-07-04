#pragma once

#include "Loaded_HB_Data.h"

#include "../Controllers/ControllerBase.h"

namespace RB::HBox
{
	#define GET_TARGET_BOX_DATA_CONTROLLER static_cast<HBox::iTargetBoxDataController*>(Controllers::GetController(Controllers::ControllerType::TARGET_BOX_DATA_CONTROLLER))

	class iTargetBoxDataController : public Controllers::ControllerBase
	{
	public:
		virtual Loaded_HB_Data* GetData(Sprites::SPRITE_TYPE spriteType) = 0;
		virtual Loaded_HB_Data* CreateData(Sprites::SPRITE_TYPE spriteType) = 0;
		virtual std::string GetPath(Sprites::SPRITE_TYPE spriteType) = 0;
	};
}
