#include "PlayerBoxSpecs.h"

#include "iSelector.h"

namespace RB::Collisions
{
	PlayerBoxSpecs::PlayerBoxSpecs(std::string path, RB::Sprites::SpriteEnum spriteType)
	{
		_path = path;
		_spriteType = spriteType;
	}

	PlayerBoxSpecs::PlayerBoxSpecs(std::string path, RB::Sprites::SpriteEnum spriteType, PlayerBox box)
	{
		_path = path;
		_spriteType = spriteType;

		GetSelector()->PushBack(box);
	}

	void PlayerBoxSpecs::OnFixedUpdate()
	{
		_selector.OnFixedUpdate();
	}

	void PlayerBoxSpecs::AddBox(PlayerBox box)
	{
		GetSelector()->PushBack(box);
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
}