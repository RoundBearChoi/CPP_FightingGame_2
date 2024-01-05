#include "LoadedPlayerBoxData.h"

namespace RB::Collisions
{
	void LoadedPlayerBoxData::Add(PlayerBoxSpecs specs)
	{
		_vecSpecs.push_back(specs);

		_RefreshIterators();
	}

	void LoadedPlayerBoxData::SetCharacterType(RB::Players::CharacterType characterType)
	{
		_characterType = characterType;
	}

	RB::Players::CharacterType LoadedPlayerBoxData::GetCharacterType()
	{
		return _characterType;
	}

	PlayerBoxSpecs* LoadedPlayerBoxData::GetSpecs(RB::Sprites::SpriteEnum spriteType)
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

	PlayerBoxSpecs* LoadedPlayerBoxData::GetSpecs(RB::Sprites::SpriteEnum spriteType, unsigned int frame)
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
		}

		return nullptr;
	}

	void LoadedPlayerBoxData::EraseSpecs(RB::Sprites::SpriteEnum spriteType, unsigned int frame)
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
						i->GetSelector()->EraseSelected();
						return;
					}
				}
			}
		}
	}

	void LoadedPlayerBoxData::_RefreshIterators()
	{
		for (auto i = _vecSpecs.begin(); i != _vecSpecs.end(); i++)
		{
			i->GetSelector()->SetRefreshed(false);
		}
	}
}