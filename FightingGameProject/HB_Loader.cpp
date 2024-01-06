#include "HB_Loader.h"

namespace RB::HBox
{
	void HB_Loader::Init()
	{
		//load every hbox datalist
		_vecData.push_back(_loader.Load(_dir + "fighter_0_idle" + _extention, RB::Sprites::SpriteType::aku_idle));
		_vecData.push_back(_loader.Load(_dir + "fighter_0_walk" + _extention, RB::Sprites::SpriteType::aku_walk));
		_vecData.push_back(_loader.Load(_dir + "fighter_0_jab" + _extention, RB::Sprites::SpriteType::aku_jab));
		_vecData.push_back(_loader.Load(_dir + "fighter_0_wince" + _extention, RB::Sprites::SpriteType::aku_wince));
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

	Loaded_HB_Data* HB_Loader::GetData(RB::Sprites::SpriteType spriteEnum)
	{
		for (auto i = _vecData.begin(); i != _vecData.end(); i++)
		{
			if ((*i).GetSpriteEnum() == spriteEnum)
			{
				return &(*i);
			}
		}

		return nullptr;
	}

	const std::string& HB_Loader::GetPath(RB::Sprites::SpriteType spriteEnum) const
	{
		const HBoxDataListPath& p = _loader.GetDataListPath(spriteEnum);

		return p.GetPath();

		const std::string& str = p.GetPath();

		return str;
	}
}