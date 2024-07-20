#pragma once
#include <string>
#include <vector>

#include "HBoxLoader.h"
#include "Loaded_HB_Data.h"
#include "SpriteType.h"
#include "HBoxType.h"

namespace RB::HBox
{
	class HB_Container
	{
	public:
		void Init();
		void OnFixedUpdate();
		void OnUpdate();

		void SetDir(std::string dir, HBoxType boxType);
		Loaded_HB_Data* GetData(RB::Sprites::SpriteType spriteType);
		Loaded_HB_Data* CreateData(RB::Sprites::SpriteType spriteType);
		std::string CreatePath(RB::Sprites::SpriteType spriteType);
		std::string GetPath(RB::Sprites::SpriteType spriteType);

	private:
		HBoxLoader _loader;
		std::vector<Loaded_HB_Data> _vecData;

		const std::string _none = "none";
		std::string _dir = "HBDirectory/";
		HBoxType _boxType = HBoxType::NONE;
		std::string _extention = ".HBoxSpecs";
	};
}
