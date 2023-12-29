#pragma once

#include <vector>
#include "HBoxLoader.h"

namespace RB::HBox
{
	class HB
	{
	public:
		void Init();
		void OnFixedUpdate();

		HBox_Layer_1* GetL1(RB::Sprites::SpriteEnum spriteEnum);
		const std::string& GetPath(RB::Sprites::SpriteEnum spriteEnum) const;

		void PresetDir(std::string dir);

	private:
		HBoxLoader _loader;
		std::vector<HBox_Layer_1> _vecL1;

		const std::string _none = "none";
		std::string _dir = "AssignHBDataDirectory/";
		std::string _extention = ".HurtBoxSpecs";
	};
}