#pragma once
#include <vector>
#include "SpriteEnum.h"
#include "HBox_Layer_0.h"

namespace RB::HBox
{
	class HBoxDataList
	{
	public:
		HBoxDataList(RB::Sprites::SpriteEnum spriteEnum);
		~HBoxDataList() = default;

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