#pragma once
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
#include <vector>
#include "json.h"
#include "JGetter.h"
#include "HurtBoxData.h"

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
		std::vector<HurtBoxData> LoadData(std::string path, int frame);

	public:
		void LoadSample();
		void SaveSample();

	public:
		HurtBoxData GetHurtBoxData(const json_array_s& array, size_t index);
	};
}