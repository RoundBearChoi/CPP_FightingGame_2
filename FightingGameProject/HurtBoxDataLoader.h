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
		void LoadSample();
		void SaveSample();
		void LoadSample2();
		void SaveSample2();

	public:
		HurtBoxData GetHurtBoxData_FromSample(const json_object_s&, int index);
		HurtBoxData GetHurtBoxData_FromSample2(const json_array_s& array, int index);
	};
}