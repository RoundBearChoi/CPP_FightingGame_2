#include "PlayerBoxSpecs.h"

#include "iSelector.h"

namespace RB::Collisions
{
	void PlayerBoxSpecs::OnFixedUpdate()
	{
		_selector.OnFixedUpdate();
	}

	void PlayerBoxSpecs::SetSpriteType(RB::Sprites::SpriteEnum spriteEnum)
	{
		_spriteType = spriteEnum;
	}

	RB::Sprites::SpriteEnum PlayerBoxSpecs::GetSpriteType()
	{
		return _spriteType;
	}

	RB::iSelector<PlayerBox>* PlayerBoxSpecs::GetSelector()
	{
		return &_selector;
	}

	bool PlayerBoxSpecs::BoxExists(unsigned int frame)
	{
		const auto& vec = GetSelector()->GetVector();

		auto it = vec.begin();

		for (auto i = vec.begin(); i != vec.end(); i++)
		{
			if (i->mFrame == frame)
			{
				return true;
			}
		}

		return false;
	}

	const RB::Collisions::PlayerBox& PlayerBoxSpecs::GetBox(unsigned int frame)
	{
		const auto& vec = GetSelector()->GetVector();

		for (auto i = vec.begin(); i != vec.end(); i++)
		{
			if (i->mFrame == frame)
			{
				return *i;
			}
		}

		return _emptyBox;
	}

	RB::Collisions::PlayerBox* PlayerBoxSpecs::GetBox_ptr(unsigned int frame)
	{
		auto* vec = GetSelector()->GetVector_ptr();

		for (auto i = vec->begin(); i != vec->end(); i++)
		{
			if (i->mFrame == frame)
			{
				return &(*i);
			}
		}

		return nullptr;
	}

	void PlayerBoxSpecs::AddBox(PlayerBox box)
	{
		GetSelector()->PushBack(box);
	}
}