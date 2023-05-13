#pragma once
#include <iostream>
#include <fstream>
#include <cassert>
#include <sstream>
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

	public:
		HurtBoxData GetHurtBoxData(const json_object_s&, int index);
	};
}