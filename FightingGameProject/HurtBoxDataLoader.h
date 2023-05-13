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
		void LoadData(std::string path, int frame, std::vector<HurtBoxData> &vec);

	public:
		void LoadSample();
		void SaveSample();

	public:
		HurtBoxData GetHurtBoxData(const json_array_s& array, size_t index);
	};
}