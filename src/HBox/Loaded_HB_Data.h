#pragma once

#include <vector>

#include "AABB_Set.h"
#include "HBoxType.h"

#include "../Sprites/SpriteType.h"

namespace RB::HBox
{
	class Loaded_HB_Data
	{
	public:
		Loaded_HB_Data(Sprites::SPRITE_TYPE spriteType, HBoxType boxType);
		~Loaded_HB_Data() = default;

	public:
		void OnFixedUpdate();
		void OnUpdate();
		void AddSet(AABB_Set data);
		const std::vector<AABB_Set>& Get_AABB_Sets();
		AABB_Set* GetHBoxDataByFrame(unsigned int frame);
		Sprites::SPRITE_TYPE GetSpriteType();

	private:
		Sprites::SPRITE_TYPE _spriteType = Sprites::SPRITE_TYPE::NONE;
		std::vector<AABB_Set> _vec_AABB_Sets;
		HBoxType _boxType = HBoxType::NONE;
	};
}
