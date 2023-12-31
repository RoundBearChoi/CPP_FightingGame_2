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
			if (i->GetSpriteType() == spriteType)
			{
				return &(*i);
			}
		}

		return nullptr;
	}

	PlayerBoxSpecs* LoadedPlayerBoxSpecs::GetSpecs(RB::Sprites::SpriteEnum spriteType, unsigned int frame)
	{
		for (auto i = _vecSpecs.begin(); i != _vecSpecs.end(); i++)
		{
			if (i->GetSpriteType() == spriteType)
			{
				const auto& vec = i->GetSelector()->GetVector();

				for (auto j = vec.begin(); j != vec.end(); j++)
				{
					if (j->mFrame == frame)
					{
						return &(*i);
					}
				}
			}

			//if (i->_spriteType == spriteType)
			//{
			//	if (i->mFrame == frame)
			//	{
			//		return &(*i);
			//	}
			//}
		}

		return nullptr;
	}
}