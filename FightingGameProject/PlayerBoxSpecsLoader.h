#pragma once

#include <string>
#include <vector>

#include "SpriteEnum.h"
#include "PlayerBoxSpecs.h"

namespace RB::Collisions
{
	class PlayerBoxSpecsLoader
	{
	public:
		PlayerBoxSpecsLoader() = default;
		~PlayerBoxSpecsLoader() = default;

	public:
		void LoadSpecs(std::string path, RB::Sprites::SpriteEnum spriteEnum);

	private:
		std::vector<PlayerBoxSpecs> _vecSpecs;
	};
}