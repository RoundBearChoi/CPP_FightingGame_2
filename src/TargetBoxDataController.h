#pragma once

#include <string>

#include "HBox/iTargetBoxDataController.h"
#include "HBox/Loaded_HB_Data.h"
#include "HBox/HB_Container.h"
#include "SpriteType.h"

namespace RB::HBox
{
	class TargetBoxDataController : public iTargetBoxDataController
	{
	public:
		TargetBoxDataController(std::string dir);
		~TargetBoxDataController() override {};

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		Loaded_HB_Data* GetData(RB::Sprites::SpriteType spriteType) override;
		Loaded_HB_Data* CreateData(RB::Sprites::SpriteType spriteType) override;
		std::string GetPath(RB::Sprites::SpriteType spriteType) override;

	private:
		HB_Container _hbContainer;
	};
}
