#include "SpriteDataController.h"

namespace RB::Sprites
{
	SpriteDataController::SpriteDataController()
	{
		SetHash(typeid(*this));
	}

	SpriteDataController::~SpriteDataController()
	{
		for (size_t i = 0; i < _vecEnumStrings.size(); i++)
		{
			delete _vecEnumStrings[i];
		}
	}

	void SpriteDataController::Init()
	{
		_vecEnumStrings.push_back(new SpriteEnumString(SpriteEnum::NONE, "NONE"));
		_vecEnumStrings.push_back(new SpriteEnumString(SpriteEnum::fighter_0_idle, "fighter_0_idle"));
		_vecEnumStrings.push_back(new SpriteEnumString(SpriteEnum::fighter_0_walk, "fighter_0_walk"));
		_vecEnumStrings.push_back(new SpriteEnumString(SpriteEnum::fighter_0_jump_up, "fighter_0_jump_up"));
		_vecEnumStrings.push_back(new SpriteEnumString(SpriteEnum::fighter_0_fall, "fighter_0_fall"));
	}

	void SpriteDataController::OnUpdate()
	{

	}

	void SpriteDataController::OnFixedUpdate()
	{

	}

	std::string SpriteDataController::GetString(SpriteEnum spriteEnum)
	{
		for (size_t i = 0; i < _vecEnumStrings.size(); i++)
		{
			if (_vecEnumStrings[i]->GetEnum() == spriteEnum)
			{
				return _vecEnumStrings[i]->GetString();
			}
		}

		return "NONE";
	}
}