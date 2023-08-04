#pragma once
#include "ControllerBase.h"
#include "HBoxDataset.h"

namespace RB::HBox
{
	class iHurtBoxDataController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual HBoxDataset* GetDataset(RB::Sprites::SpriteEnum spriteEnum) = 0;
		virtual const std::string& GetPath(RB::Sprites::SpriteEnum spriteEnum) = 0;
	};

	extern iHurtBoxDataController* HURTBOX_DATA_CONTROLLER;
}