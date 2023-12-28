#include "HB.h"

namespace RB::HBox
{
	void HB::Init()
	{
		//load every hbox datalist
		_vecLists.push_back(_loader.LoadDataList(_dir + "fighter_0_idle" + _extention, RB::Sprites::SpriteEnum::aku_idle));
		_vecLists.push_back(_loader.LoadDataList(_dir + "fighter_0_walk" + _extention, RB::Sprites::SpriteEnum::aku_walk));
		_vecLists.push_back(_loader.LoadDataList(_dir + "fighter_0_jab" + _extention, RB::Sprites::SpriteEnum::aku_0_jab));
		_vecLists.push_back(_loader.LoadDataList(_dir + "fighter_0_wince" + _extention, RB::Sprites::SpriteEnum::aku_wince));
	}

	void HB::OnFixedUpdate()
	{
		for (auto i = _vecLists.begin(); i != _vecLists.end(); i++)
		{
			(*i).OnFixedUpdate();
		}
	}

	HBoxDataList* HB::GetDataList(RB::Sprites::SpriteEnum spriteEnum)
	{
		for (auto i = _vecLists.begin(); i != _vecLists.end(); i++)
		{
			if ((*i).GetSpriteEnum() == spriteEnum)
			{
				return &(*i);
			}
		}

		return nullptr;
	}

	const std::string& HB::GetPath(RB::Sprites::SpriteEnum spriteEnum) const
	{
		const HBoxDataListPath& p = _loader.GetDataListPath(spriteEnum);

		return p.GetPath();

		const std::string& str = p.GetPath();

		return str;
	}

	void HB::PresetDir(std::string dir)
	{
		std::cout << std::endl;
		std::cout << "presetting dir: " << dir << std::endl;
		_dir = dir;
	}
}