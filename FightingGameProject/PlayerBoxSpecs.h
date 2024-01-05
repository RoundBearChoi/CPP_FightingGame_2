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
		const RB::Collisions::PlayerBox& GetBox(unsigned int frame);
		RB::Collisions::PlayerBox* GetBox_ptr(unsigned int frame);
		void AddBox(PlayerBox box);

	private:
		RB::Selector<PlayerBox> _selector;
		RB::Sprites::SpriteEnum _spriteType = RB::Sprites::SpriteEnum::NONE;
		const RB::Collisions::PlayerBox _emptyBox{ 0, 0.0f, 0.0f, 0.0f, 0.0f };
	};
}