#pragma once

#include "HBox_Layer_2.h"

#include "iHurtBoxDataController.h"

namespace RB::HBox
{
	class HurtBoxDataController : public iHurtBoxDataController
	{
	public:
		HurtBoxDataController(std::string dir);
		~HurtBoxDataController() override {};

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		HBox_Layer_1* Get_L1(RB::Sprites::SpriteEnum spriteEnum) override;
		const std::string& GetPath(RB::Sprites::SpriteEnum spriteEnum) const override;

	private:
		HBox_Layer_2 _L2;
	};
}