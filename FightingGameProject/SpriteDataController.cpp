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

		//for (size_t i = 0; i < _vecEnumStrings.size(); i++)
		//{
		//	delete _vecEnumStrings[i];
		//}
	}

	void SpriteDataController::Init()
	{
		_vecEnumStrings.reserve((size_t)SpriteEnum::COUNT);
		_vecEnumStrings.push_back(new SpriteEnumString(SpriteEnum::NONE, "NONE"));
		_vecEnumStrings.push_back(new SpriteEnumString(SpriteEnum::aku_idle, "fighter_0_idle"));
		_vecEnumStrings.push_back(new SpriteEnumString(SpriteEnum::aku_walk, "fighter_0_walk"));
		_vecEnumStrings.push_back(new SpriteEnumString(SpriteEnum::aku_jump_up_0, "fighter_0_jump_up"));
		_vecEnumStrings.push_back(new SpriteEnumString(SpriteEnum::aku_jump_up_1, "fighter_0_fall"));
		_vecEnumStrings.push_back(new SpriteEnumString(SpriteEnum::aku_0_jab, "fighter_0_jab"));
		_vecEnumStrings.push_back(new SpriteEnumString(SpriteEnum::aku_wince, "fighter_0_wince"));
	}

	void SpriteDataController::OnUpdate()
	{

	}

	void SpriteDataController::OnFixedUpdate()
	{

	}

	const std::string& SpriteDataController::GetString(SpriteEnum spriteEnum)
	{
		for (auto i = _vecEnumStrings.begin(); i != _vecEnumStrings.end(); i++)
		{
			if ((*i)->GetEnum() == spriteEnum)
			{
				return (*i)->GetString();
			}
		}

		//for (size_t i = 0; i < _vecEnumStrings.size(); i++)
		//{
		//	if (_vecEnumStrings[i]->GetEnum() == spriteEnum)
		//	{
		//		return _vecEnumStrings[i]->GetString();
		//	}
		//}

		return _empty;
	}
}