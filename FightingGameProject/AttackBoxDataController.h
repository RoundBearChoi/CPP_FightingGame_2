#pragma once

#include <string>

#include "iAttackBoxDataController.h"
#include "Loaded_HB_Data.h"
#include "HB_Container.h"

namespace RB::HBox
{
	class AttackBoxDataController : public iAttackBoxDataController
	{
	public:
		AttackBoxDataController(std::string dir);
		~AttackBoxDataController() override {};

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		Loaded_HB_Data* GetData(RB::Sprites::SpriteType spriteType) override;
		const std::string& GetPath(RB::Sprites::SpriteType spriteType) const override;

	private:
		HB_Container _hbContainer;
	};
}
