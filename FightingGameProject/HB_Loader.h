#pragma once
#include <string>
#include <vector>

#include "_HBoxLoader.h"
#include "Loaded_HB_Data.h"

namespace RB::HBox
{
	class HB_Loader
	{
	public:
		void Init();
		void OnFixedUpdate();
		void OnUpdate();

		void SetDir(std::string dir);
		Loaded_HB_Data* GetData(RB::Sprites::SpriteEnum spriteEnum);
		const std::string& GetPath(RB::Sprites::SpriteEnum spriteEnum) const;

	private:
		_HBoxLoader _loader;
		std::vector<Loaded_HB_Data> _vecData;

		const std::string _none = "none";
		std::string _dir = "HBDirectory/";
		std::string _extention = ".HurtBoxSpecs";
	};
}