#pragma once

#include "Loaded_HB_Data.h"

#include "../Controllers/ControllerBase.h"

namespace RB::HBox
{
	#define GET_TARGET_BOX_DATA_CONTROLLER static_cast<RB::HBox::iTargetBoxDataController*>(RB::Controllers::GetController(Controllers::ControllerType::TARGET_BOX_DATA_CONTROLLER))

	class iTargetBoxDataController : public RB::Controllers::ControllerBase
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