#pragma once
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
#include <vector>
#include "json.h"
#include "JGetter.h"
#include "HurtBoxSpecs.h"
#include "HurtBoxData.h"
#include "HurtBoxDataSet.h"

namespace RB::HurtBox
{
	class HurtBoxSpecsLoader
	{
	public:
		HurtBoxSpecsLoader() = default;
		~HurtBoxSpecsLoader() = default;

	public:
		void Init();
		void SaveSample();

	public:
		/// <summary>
		/// make sure to free root after use
		/// </summary>
		json_value_s* LoadRoot(std::string path);

	public:
		HurtBoxDataSet LoadDataSet(const std::string path, const RB::Sprites::SpriteID spriteID);
		HurtBoxDataSet LoadDataSet(const json_object_s& wholeObj, const RB::Sprites::SpriteID spriteID);
		std::vector<HurtBoxSpecs> ParseData(const json_object_s& wholeObj, const size_t frame);

	public:
		HurtBoxSpecs GetHurtBoxSpecs(const json_array_s& array, size_t index);
	};
}