#pragma once
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
#include <vector>
#include "json.h"
#include "JGetter.h"
#include "HurtBoxData.h"
#include "HurtBoxDataSet.h"

namespace RB::HurtBox
{
	class HurtBoxDataLoader
	{
	public:
		HurtBoxDataLoader() = default;
		~HurtBoxDataLoader() = default;

	public:
		void Init();

	public:
		/// <summary>
		/// make sure to free root after use
		/// </summary>
		json_value_s* LoadRoot(std::string path);
		std::vector<HurtBoxData> ParseData(json_value_s* root, size_t frame);

	public:
		void LoadSample();
		void SaveSample();

	public:
		HurtBoxData GetHurtBoxData(const json_array_s& array, size_t index);
	};
}