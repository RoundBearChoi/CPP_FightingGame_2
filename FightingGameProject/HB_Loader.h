#pragma once
#include <string>
#include <vector>

#include "_HBoxLoader.h"
#include "Loaded_HB_Data.h"
#include "SpriteType.h"

namespace RB::HBox
{
	class HB_Loader
	{
	public:
		void Init();
		void OnFixedUpdate();
		void OnUpdate();

		void SetDir(std::string dir);
		Loaded_HB_Data* GetData(RB::Sprites::SpriteType spriteType);
		const std::string& GetPath(RB::Sprites::SpriteType spriteType) const;

	private:
		std::string _CreatePath(RB::Sprites::SpriteType spriteType);

		_HBoxLoader _loader;
		std::vector<Loaded_HB_Data> _vecData;

		const std::string _none = "none";
		std::string _dir = "HBDirectory/";
		std::string _extention = ".HBoxSpecs";
	};
}
