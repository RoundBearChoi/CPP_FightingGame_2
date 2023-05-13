#pragma once
#include <iostream>
#include <fstream>

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
		void SaveSample();
	};
}