#include "HB_Loader.h"

namespace RB::HBox
{
	void HB_Loader::Init()
	{
		//load every hbox datalist
		_vecData.push_back(_loader.Load(_CreatePath(RB::Sprites::SpriteType::fighter_0_idle), RB::Sprites::SpriteType::fighter_0_idle));
		_vecData.push_back(_loader.Load(_CreatePath(RB::Sprites::SpriteType::fighter_0_walk), RB::Sprites::SpriteType::fighter_0_walk));
		_vecData.push_back(_loader.Load(_CreatePath(RB::Sprites::SpriteType::fighter_0_jab), RB::Sprites::SpriteType::fighter_0_jab));
		_vecData.push_back(_loader.Load(_CreatePath(RB::Sprites::SpriteType::fighter_0_strong_punch), RB::Sprites::SpriteType::fighter_0_strong_punch));
		_vecData.push_back(_loader.Load(_CreatePath(RB::Sprites::SpriteType::fighter_0_wince), RB::Sprites::SpriteType::fighter_0_wince));
		_vecData.push_back(_loader.Load(_CreatePath(RB::Sprites::SpriteType::fighter_0_strong_wince), RB::Sprites::SpriteType::fighter_0_strong_wince));
	}

	void HB_Loader::OnFixedUpdate()
	{
		for (auto i = _vecData.begin(); i != _vecData.end(); i++)
		{
			(*i).OnFixedUpdate();
		}
	}

	void HB_Loader::OnUpdate()
	{
		for (auto i = _vecData.begin(); i != _vecData.end(); i++)
		{
			(*i).OnUpdate();
		}
	}

	void HB_Loader::SetDir(std::string dir)
	{
		std::cout << std::endl;
		std::cout << "presetting dir: " << dir << std::endl;
		_dir = dir;
	}

	Loaded_HB_Data* HB_Loader::GetData(RB::Sprites::SpriteType spriteType)
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

	const std::string& HB_Loader::GetPath(RB::Sprites::SpriteType spriteType) const
	{
		const HBoxDataListPath& p = _loader.GetDataListPath(spriteType);

		return p.GetPath();

		const std::string& str = p.GetPath();

		return str;
	}

	std::string HB_Loader::_CreatePath(RB::Sprites::SpriteType spriteType)
	{
		std::string str = spriteType._to_string();
		return _dir + str + _extention;
	}
}