#pragma once
#include <iostream>
#include "SpriteEnum.h"

namespace RB::HBox
{
	class HBoxDataSetPath
	{
	public:
		HBoxDataSetPath(std::string path, RB::Sprites::SpriteEnum spriteEnum)
		{
			_path = path;
			_spriteEnum = spriteEnum;
		}

		~HBoxDataSetPath() = default;

	public:
		const std::string& GetPath()
		{
			return _path;
		}
		
		RB::Sprites::SpriteEnum GetSpriteEnum()
		{
			return _spriteEnum;
		}

	private:
		std::string _path = "";
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
	};
}