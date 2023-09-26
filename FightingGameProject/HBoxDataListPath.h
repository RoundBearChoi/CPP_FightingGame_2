#pragma once
#include <iostream>
#include "SpriteEnum.h"

namespace RB::HBox
{
	class HBoxDataListPath
	{
	public:
		HBoxDataListPath(std::string path, RB::Sprites::SpriteEnum spriteEnum)
		{
			_path = path;
			_spriteEnum = spriteEnum;
		}

		~HBoxDataListPath() = default;

	public:
		const std::string& GetPath() const
		{
			return _path;
		}
		
		const RB::Sprites::SpriteEnum& GetSpriteEnum() const
		{
			return _spriteEnum;
		}

	private:
		std::string _path = "";
		RB::Sprites::SpriteEnum _spriteEnum = RB::Sprites::SpriteEnum::NONE;
	};
}