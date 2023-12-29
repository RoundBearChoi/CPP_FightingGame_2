#pragma once
#include <vector>
#include "SpriteEnum.h"
#include "HBox_Layer_0.h"

namespace RB::HBox
{
	class HBox_Layer_1
	{
	public:
		HBox_Layer_1(RB::Sprites::SpriteEnum spriteEnum);
		~HBox_Layer_1() = default;

	public:
		void OnFixedUpdate();
		void AddHBoxData(HBox_Layer_0 data);
		const std::vector<HBox_Layer_0>& GetVecL0();
		HBox_Layer_0* GetHBoxDataByFrame(unsigned int frame);
		RB::Sprites::SpriteEnum GetSpriteEnum();

	private:
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
		std::vector<HBox_Layer_0> _vecHB_L0;
	};
}