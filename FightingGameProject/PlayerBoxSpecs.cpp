#include "PlayerBoxSpecs.h"

namespace RB::Collisions
{
	void PlayerBoxSpecs::SetSpriteType(RB::Sprites::SpriteEnum spriteEnum)
	{
		_spriteType = spriteEnum;
	}

	RB::Sprites::SpriteEnum PlayerBoxSpecs::GetSpriteType()
	{
		return _spriteType;
	}

	RB::Selector<PlayerBox>* PlayerBoxSpecs::GetSelector()
	{
		return &_selector;
	}

	bool PlayerBoxSpecs::BoxExists(unsigned int frame, PlayerBox& box)
	{
		const auto& vec = GetSelector()->GetVector();

		auto it = vec.begin();

		for (auto i = vec.begin(); i != vec.end(); i++)
		{
			if (i->mFrame == frame)
			{
				box = *i;
				//PlayerBox box = *i;
				return true;
			}
		}

		return false;
	}
}