#pragma once

#include <vector>
#include <cassert>

#include "AABB.h"
#include "Loaded_HB_Data.h"
#include "HBox/HBoxType.h"

namespace RB::HBox
{
	class HBoxLoader
	{
	public:
		HBoxLoader() = default;
		~HBoxLoader() = default;

	public:
		void InitSample(std::string path);
		void SaveSample();

	public:
		Loaded_HB_Data Load(const std::string path, const RB::Sprites::SpriteType spriteType, HBoxType boxType);
		std::vector<RB::Collisions::AABB> ParseData(const json_object_s& wholeObj, const unsigned int frame);
		std::string ParseName(const json_object_s& wholeObj, const unsigned int frame);

	public:
		RB::Collisions::AABB GetAABB(const json_array_s& array, unsigned int index);
		
	private:
		std::string _samplePath;
	};
}
