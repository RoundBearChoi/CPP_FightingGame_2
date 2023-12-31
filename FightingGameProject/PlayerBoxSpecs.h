#pragma once

#include "SpriteEnum.h"
#include "Selector.h"
#include "PlayerBox.h"

namespace RB::Collisions
{
	class PlayerBoxSpecs
	{
	public:
		PlayerBoxSpecs() = default;
		~PlayerBoxSpecs() = default;

	public:
		void SetSpriteType(RB::Sprites::SpriteEnum spriteEnum);
		RB::Sprites::SpriteEnum GetSpriteType();
		RB::iSelector<PlayerBox>* GetSelector();
		bool BoxExists(unsigned int frame, PlayerBox& box);

	private:
		RB::Selector<PlayerBox> _selector;
		RB::Sprites::SpriteEnum _spriteType = RB::Sprites::SpriteEnum::NONE;
	};
}