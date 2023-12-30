#pragma once
#include <vector>
#include "SpriteEnum.h"
#include "AABB_Set.h"

namespace RB::HBox
{
	class Loaded_HB_Data
	{
	public:
		Loaded_HB_Data(RB::Sprites::SpriteEnum spriteEnum);
		~Loaded_HB_Data() = default;

	public:
		void OnFixedUpdate();
		void AddSet(AABB_Set data);
		const std::vector<AABB_Set>& Get_AABB_Sets();
		AABB_Set* GetHBoxDataByFrame(unsigned int frame);
		RB::Sprites::SpriteEnum GetSpriteEnum();

	private:
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
		std::vector<AABB_Set> _vec_AABB_Sets;
	};
}