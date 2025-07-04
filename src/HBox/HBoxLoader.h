#pragma once

#include <vector>
#include <cassert>

#include "HBoxType.h"
#include "Loaded_HB_Data.h"

#include "../Collisions/AABB.h"

namespace RB::HBox
{
	class HBoxLoader
	{
	public:
		HBoxLoader() = default;
		~HBoxLoader() = default;

	public:
		void InitSample(std::string path);

	public:
		Loaded_HB_Data Load(const std::string path, const Sprites::SPRITE_TYPE spriteType, HBoxType boxType);
		std::vector<Collisions::AABB> ParseData(const json_object_s& wholeObj, const unsigned int frame);
		std::string ParseName(const json_object_s& wholeObj, const unsigned int frame);

	public:
		Collisions::AABB GetAABB(const json_array_s& array, unsigned int index);
	};
}
