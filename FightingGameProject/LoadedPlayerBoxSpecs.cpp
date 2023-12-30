#include "LoadedPlayerBoxSpecs.h"

namespace RB::Collisions
{
	void LoadedPlayerBoxSpecs::Add(PlayerBoxSpecs specs)
	{
		_vecSpecs.push_back(specs);
	}

	void LoadedPlayerBoxSpecs::SetCharacterType(RB::Players::CharacterType characterType)
	{
		_characterType = characterType;
	}

	RB::Players::CharacterType LoadedPlayerBoxSpecs::GetCharacterType()
	{
		return _characterType;
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