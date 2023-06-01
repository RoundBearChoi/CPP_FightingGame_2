#pragma once
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
#include <vector>
#include "json.h"
#include "JGetter.h"
#include "AABB.h"
#include "HBoxData.h"
#include "HBoxDataSet.h"
#include "HurtBoxDataSetPath.h"

namespace RB::HurtBox
{
	class HurtBoxLoader
	{
	public:
		HurtBoxLoader() = default;
		~HurtBoxLoader() = default;

	public:
		void Init();
		void SaveSample();

	public:
		/// <summary>
		/// make sure to free root after use
		/// </summary>
		json_value_s* LoadRoot(std::string path);
		/// <summary>
		/// only use during initialization (vector addresses)
		/// </summary>
		HBoxDataSet LoadDataSet(const std::string path, const RB::Sprites::SpriteEnum spriteEnum);
		std::vector<RB::Collisions::AABB> ParseData(const json_object_s& wholeObj, const size_t frame);
		std::string ParseName(const json_object_s& wholeObj, const size_t frame);

	public:
		RB::Collisions::AABB GetHurtBoxAABB(const json_array_s& array, size_t index);
		RB::HurtBox::HurtBoxDataSetPath* GetDataSetPath(RB::Sprites::SpriteEnum spriteEnum);

	private:
		std::vector<HurtBoxDataSetPath> _vecDataSetPaths;
	};
}