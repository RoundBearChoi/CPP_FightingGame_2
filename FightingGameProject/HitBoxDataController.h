#pragma once

#include "HBox_Layer_2.h"

#include "iHitBoxDataController.h"

namespace RB::HBox
{
	class HitBoxDataController : public iHitBoxDataController
	{
	public:
		HitBoxDataController(std::string dir);
		~HitBoxDataController() override {};

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		HBox_Layer_1* Get_L1(RB::Sprites::SpriteEnum spriteEnum) override;
		const std::string& GetPath(RB::Sprites::SpriteEnum spriteEnum) const override;

	private:
		HBox_Layer_2 _L2;
	};
}