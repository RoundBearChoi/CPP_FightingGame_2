#pragma once

#include <string>

#include "Loaded_HB_Data.h"
#include "HB_Container.h"

#include "iTargetBoxDataController.h"

#include "../Sprites/SpriteType.h"

namespace RB::HBox
{
	class TargetBoxDataController : public iTargetBoxDataController
	{
	public:
		TargetBoxDataController();
		~TargetBoxDataController() override {};

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		Loaded_HB_Data* GetData(Sprites::SPRITE_TYPE spriteType) override;
		Loaded_HB_Data* CreateData(Sprites::SPRITE_TYPE spriteType) override;
		std::string GetPath(Sprites::SPRITE_TYPE spriteType) override;

	private:
		HB_Container _hbContainer;
	};
}
