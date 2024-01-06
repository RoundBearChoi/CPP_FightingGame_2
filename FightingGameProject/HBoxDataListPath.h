#pragma once
#include <string>
#include "SpriteType.h"

namespace RB::HBox
{
	class HBoxDataListPath
	{
	public:
		HBoxDataListPath(std::string path, RB::Sprites::SpriteType spriteType)
		{
			_path = path;
			_spriteType = spriteType;
		}

		~HBoxDataListPath() = default;

	public:
		const std::string& GetPath() const
		{
			return _path;
		}
		
		const RB::Sprites::SpriteType& GetSpriteType() const
		{
			return _spriteType;
		}

	private:
		std::string _path = "";
		RB::Sprites::SpriteType _spriteType = RB::Sprites::SpriteType::NONE;
	};
}