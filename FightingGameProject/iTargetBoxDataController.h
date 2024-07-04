#pragma once
#include "ControllerT.h"

#include "Loaded_HB_Data.h"

namespace RB::HBox
{
	class iTargetBoxDataController : public RB::Controllers::ControllerT<iTargetBoxDataController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual Loaded_HB_Data* GetData(RB::Sprites::SpriteType spriteType) = 0;
		virtual std::string GetPath(RB::Sprites::SpriteType spriteType) = 0;
	};
}
