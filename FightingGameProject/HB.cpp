#include "HB.h"

namespace RB::HBox
{
	void HB::Init()
	{
		//load every hbox datalist
		_vecLists.push_back(_loader.LoadDataList(_dir + "fighter_0_idle" + _extention, RB::Sprites::SpriteEnum::fighter_0_idle));
		_vecLists.push_back(_loader.LoadDataList(_dir + "fighter_0_walk" + _extention, RB::Sprites::SpriteEnum::fighter_0_walk));
		_vecLists.push_back(_loader.LoadDataList(_dir + "fighter_0_jab" + _extention, RB::Sprites::SpriteEnum::fighter_0_jab));
	}

	HBoxDataList* HB::GetDataList(RB::Sprites::SpriteEnum spriteEnum)
	{
		for (size_t i = 0; i < _vecLists.size(); i++)
		{
			if (_vecLists[i].GetSpriteEnum() == spriteEnum)
			{
				return &_vecLists[i];
			}
		}

		return nullptr;
	}

	const std::string& HB::GetPath(RB::Sprites::SpriteEnum spriteEnum)
	{
		HBoxDataListPath* p = _loader.GetDataListPath(spriteEnum);

		if (p != nullptr)
		{
			return p->GetPath();
		}

		return _none;
	}

	void HB::PresetDir(std::string dir)
	{
		std::cout << std::endl;
		std::cout << "presetting dir: " << dir << std::endl;
		_dir = dir;
	}
}