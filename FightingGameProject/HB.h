#pragma once

#include <vector>
#include "HBoxLoader.h"

namespace RB::HBox
{
	class HB
	{
	public:
		void Init();
		HBoxDataList* GetDataList(RB::Sprites::SpriteEnum spriteEnum);
		const std::string& GetPath(RB::Sprites::SpriteEnum spriteEnum) const;

		void PresetDir(std::string dir);

	private:
		HBoxLoader _loader;
		std::vector<HBoxDataList> _vecLists;

		const std::string _none = "none";
		std::string _dir = "AssignHBDataDirectory/";
		std::string _extention = ".HurtBoxSpecs";
	};
}