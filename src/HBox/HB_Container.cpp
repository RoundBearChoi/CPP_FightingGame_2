#include "HB_Container.h"

namespace RB::HBox
{
	void HB_Container::Init()
	{
		//load every hbox datalist

		for (int i = RB::Sprites::SpriteType::FIGHTER_0_SPRITES_START + 1; i < RB::Sprites::SpriteType::FIGHTER_0_SPRITES_END; i++)
		{
			_vecData.push_back(_loader.Load(CreatePath(RB::Sprites::SpriteType::_from_index(i)), RB::Sprites::SpriteType::_from_index((i)), _boxType));
		}

		//_vecData.push_back(_loader.Load(CreatePath(RB::Sprites::SpriteType::fighter_0_idle), RB::Sprites::SpriteType::fighter_0_idle, _boxType));
		//_vecData.push_back(_loader.Load(CreatePath(RB::Sprites::SpriteType::fighter_0_walk), RB::Sprites::SpriteType::fighter_0_walk, _boxType));
		//_vecData.push_back(_loader.Load(CreatePath(RB::Sprites::SpriteType::fighter_0_jab), RB::Sprites::SpriteType::fighter_0_jab, _boxType));
		//_vecData.push_back(_loader.Load(CreatePath(RB::Sprites::SpriteType::fighter_0_strong_punch), RB::Sprites::SpriteType::fighter_0_strong_punch, _boxType));
		//_vecData.push_back(_loader.Load(CreatePath(RB::Sprites::SpriteType::fighter_0_strong_kick), RB::Sprites::SpriteType::fighter_0_strong_kick, _boxType));
		//_vecData.push_back(_loader.Load(CreatePath(RB::Sprites::SpriteType::fighter_0_weak_wince_mid), RB::Sprites::SpriteType::fighter_0_weak_wince_mid, _boxType));
		//_vecData.push_back(_loader.Load(CreatePath(RB::Sprites::SpriteType::fighter_0_strong_wince_mid), RB::Sprites::SpriteType::fighter_0_strong_wince_mid, _boxType));
		//_vecData.push_back(_loader.Load(CreatePath(RB::Sprites::SpriteType::fighter_0_crouch_punch_weak), RB::Sprites::SpriteType::fighter_0_crouch_punch_weak, _boxType));
	}

	void HB_Container::OnFixedUpdate()
	{
		for (auto i = _vecData.begin(); i != _vecData.end(); i++)
		{
			(*i).OnFixedUpdate();
		}
	}

	void HB_Container::OnUpdate()
	{
		for (auto i = _vecData.begin(); i != _vecData.end(); i++)
		{
			(*i).OnUpdate();
		}
	}

	void HB_Container::SetDir(std::string dir, HBoxType boxType)
	{
		//std::cout << std::endl;
		//std::cout << "presetting dir: " << dir << std::endl;

		_dir = dir;
		_boxType = boxType;
	}

	Loaded_HB_Data* HB_Container::GetData(RB::Sprites::SpriteType spriteType)
	{
		for (auto i = _vecData.begin(); i != _vecData.end(); i++)
		{
			if ((*i).GetSpriteType() == spriteType)
			{
				return &(*i);
			}
		}

		return nullptr;
	}

	Loaded_HB_Data* HB_Container::CreateData(RB::Sprites::SpriteType spriteType)
	{
		Loaded_HB_Data* existing = GetData(spriteType);

		if (existing == nullptr)
		{
			Loaded_HB_Data newData{ spriteType, _boxType };

			_vecData.push_back(newData);

			return &_vecData[_vecData.size() - 1];
		}

		return existing;
	}

	std::string HB_Container::CreatePath(RB::Sprites::SpriteType spriteType)
	{
		std::string str = spriteType._to_string();
		return _dir + str + _extention;
	}

	std::string HB_Container::GetPath(RB::Sprites::SpriteType spriteType)
	{
		std::string spr = spriteType._to_string();
		std::string path = _dir + spr;
		path += _extention;

		//std::cout << "getting path.. " << path << std::endl;

		return path;
	}
}
