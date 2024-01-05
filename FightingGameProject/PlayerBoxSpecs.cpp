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

		_selector.PushBack(box);
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
		const auto& vec = _selector.GetVector();

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
		const auto& vec = _selector.GetVector();

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
		auto* vec = _selector.GetVector_ptr();

		for (auto i = vec->begin(); i != vec->end(); i++)
		{
			if (i->mFrame == frame)
			{
				return &(*i);
			}
		}

		return nullptr;
	}

	void PlayerBoxSpecs::Save()
	{
		if (_path.empty())
		{
			//maybe use a temporary location
			return;
		}


	}
}