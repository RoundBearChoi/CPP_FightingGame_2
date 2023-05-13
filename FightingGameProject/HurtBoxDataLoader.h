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

namespace RB::HurtBox
{
	class HurtBoxSpecsLoader
	{
	public:
		HurtBoxSpecsLoader() = default;
		~HurtBoxSpecsLoader() = default;

	public:
		void Init();

	public:
		/// <summary>
		/// make sure to free root after use
		/// </summary>
		json_value_s* LoadRoot(std::string path);
		std::vector<HurtBoxSpecs> ParseData(json_value_s* root, size_t frame);

	public:
		void LoadSample();
		void SaveSample();

	public:
		HurtBoxSpecs GetHurtBoxSpecs(const json_array_s& array, size_t index);
	};
}