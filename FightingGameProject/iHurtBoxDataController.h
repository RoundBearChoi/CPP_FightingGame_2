#pragma once
#include "ControllerT.h"

#include "Loaded_HB_Data.h"

namespace RB::HBox
{
	class iHurtBoxDataController : public RB::Controllers::ControllerT<iHurtBoxDataController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual Loaded_HB_Data* GetData(RB::Sprites::SpriteEnum spriteEnum) = 0;
		virtual const std::string& GetPath(RB::Sprites::SpriteEnum spriteEnum) const = 0;
	};
}