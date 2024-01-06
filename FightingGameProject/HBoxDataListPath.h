#pragma once
#include <string>
#include "SpriteEnum.h"

namespace RB::HBox
{
	class HBoxDataListPath
	{
	public:
		HBoxDataListPath(std::string path, RB::Sprites::SpriteType spriteEnum)
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
		
		const RB::Sprites::SpriteType& GetSpriteEnum() const
		{
			return _spriteEnum;
		}

	private:
		std::string _path = "";
		RB::Sprites::SpriteType _spriteEnum = RB::Sprites::SpriteType::NONE;
	};
}