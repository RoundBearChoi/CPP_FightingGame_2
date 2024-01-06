#include "SpriteDataController.h"

namespace RB::Sprites
{
	SpriteDataController::~SpriteDataController()
	{
		for (auto i = _vecEnumStrings.begin(); i != _vecEnumStrings.end(); i++)
		{
			delete (*i);
			*i = nullptr;
		}

		_vecEnumStrings.clear();
	}

	void SpriteDataController::Init()
	{
		_vecEnumStrings.reserve((size_t)SpriteType::COUNT);
		_vecEnumStrings.push_back(new SpriteTypeString(SpriteType::NONE, "NONE"));
		_vecEnumStrings.push_back(new SpriteTypeString(SpriteType::aku_idle, "fighter_0_idle"));
		_vecEnumStrings.push_back(new SpriteTypeString(SpriteType::aku_crouch, "fighter_0_crouch"));
		_vecEnumStrings.push_back(new SpriteTypeString(SpriteType::aku_walk, "fighter_0_walk"));
		_vecEnumStrings.push_back(new SpriteTypeString(SpriteType::aku_jump_up_0, "fighter_0_jump_up"));
		_vecEnumStrings.push_back(new SpriteTypeString(SpriteType::aku_jump_up_1, "fighter_0_fall"));
		_vecEnumStrings.push_back(new SpriteTypeString(SpriteType::aku_jab, "fighter_0_jab"));
		_vecEnumStrings.push_back(new SpriteTypeString(SpriteType::aku_wince, "fighter_0_wince"));
	}

	void SpriteDataController::OnUpdate()
	{

	}

	void SpriteDataController::OnFixedUpdate()
	{

	}

	const std::string& SpriteDataController::GetString(SpriteType spriteEnum)
	{
		for (auto i = _vecEnumStrings.begin(); i != _vecEnumStrings.end(); i++)
		{
			if ((*i)->GetEnum() == spriteEnum)
			{
				return (*i)->GetString();
			}
		}

		return _empty;
	}
}