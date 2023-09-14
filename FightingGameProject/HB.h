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
		const std::string& GetPath(RB::Sprites::SpriteEnum spriteEnum);

	private:
		HBoxLoader _loader;
		std::vector<HBoxDataList> _vecLists;

		std::string _none = "none";
		std::string _testing = "testing";
	};
}