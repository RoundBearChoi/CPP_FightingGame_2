#include "LoadedPlayerBoxSpecs.h"

namespace RB::Collisions
{
	void LoadedPlayerBoxSpecs::Add(PlayerBoxSpecs specs)
	{
		_vecSpecs.push_back(specs);
	}

	void LoadedPlayerBoxSpecs::SetSpriteType(RB::Sprites::SpriteEnum spriteType)
	{
		_spriteType = spriteType;
	}

	RB::Sprites::SpriteEnum LoadedPlayerBoxSpecs::GetSpriteType()
	{
		return _spriteType;
	}

	PlayerBoxSpecs* LoadedPlayerBoxSpecs::GetSpecs(RB::Sprites::SpriteEnum spriteType)
	{
		for (auto i = _vecSpecs.begin(); i != _vecSpecs.end(); i++)
		{
			if (i->mSpriteType == spriteType)
			{
				return &(*i);
			}
		}
	}
}