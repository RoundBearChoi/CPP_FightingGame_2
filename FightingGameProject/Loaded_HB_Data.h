#pragma once
#include <vector>
#include "SpriteType.h"
#include "AABB_Set.h"
#include "HBoxType.h"

namespace RB::HBox
{
	class Loaded_HB_Data
	{
	public:
		Loaded_HB_Data(RB::Sprites::SpriteType spriteType, HBoxType boxType);
		~Loaded_HB_Data() = default;

	public:
		void OnFixedUpdate();
		void OnUpdate();
		void AddSet(AABB_Set data);
		const std::vector<AABB_Set>& Get_AABB_Sets();
		AABB_Set* GetHBoxDataByFrame(unsigned int frame);
		RB::Sprites::SpriteType GetSpriteType();

	private:
		RB::Sprites::SpriteType _spriteType = RB::Sprites::SpriteType::NONE;
		std::vector<AABB_Set> _vec_AABB_Sets;
		HBoxType _boxType = HBoxType::NONE;
	};
}