#pragma once

#include <string>

#include "HB_Container.h"
#include "Loaded_HB_Data.h"

#include "iAttackBoxDataController.h"

#include "../Sprites/SpriteType.h"

namespace RB::HBox
{
	class AttackBoxDataController : public iAttackBoxDataController
	{
	public:
		AttackBoxDataController();
		~AttackBoxDataController() override {};

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
