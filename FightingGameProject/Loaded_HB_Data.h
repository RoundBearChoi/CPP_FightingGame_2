#pragma once
#include <vector>
#include "SpriteEnum.h"
#include "HBox_Layer_0.h"

namespace RB::HBox
{
	class Loaded_HB_Data
	{
	public:
		Loaded_HB_Data(RB::Sprites::SpriteEnum spriteEnum);
		~Loaded_HB_Data() = default;

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