#include "HBox_Layer_2.h"

namespace RB::HBox
{
	void HBox_Layer_2::Init()
	{
		//load every hbox datalist
		_vecL1.push_back(_loader.Load_L1(_dir + "fighter_0_idle" + _extention, RB::Sprites::SpriteEnum::aku_idle));
		_vecL1.push_back(_loader.Load_L1(_dir + "fighter_0_walk" + _extention, RB::Sprites::SpriteEnum::aku_walk));
		_vecL1.push_back(_loader.Load_L1(_dir + "fighter_0_jab" + _extention, RB::Sprites::SpriteEnum::aku_0_jab));
		_vecL1.push_back(_loader.Load_L1(_dir + "fighter_0_wince" + _extention, RB::Sprites::SpriteEnum::aku_wince));
	}

	void HBox_Layer_2::OnFixedUpdate()
	{
		for (auto i = _vecL1.begin(); i != _vecL1.end(); i++)
		{
			(*i).OnFixedUpdate();
		}
	}

	void HBox_Layer_2::SetDir(std::string dir)
	{
		std::cout << std::endl;
		std::cout << "presetting dir: " << dir << std::endl;
		_dir = dir;
	}

	HBox_Layer_1* HBox_Layer_2::GetL1(RB::Sprites::SpriteEnum spriteEnum)
	{
		for (auto i = _vecL1.begin(); i != _vecL1.end(); i++)
		{
			if ((*i).GetSpriteEnum() == spriteEnum)
			{
				return &(*i);
			}
		}

		return nullptr;
	}

	const std::string& HBox_Layer_2::GetPath(RB::Sprites::SpriteEnum spriteEnum) const
	{
		const HBoxDataListPath& p = _loader.GetDataListPath(spriteEnum);

		return p.GetPath();

		const std::string& str = p.GetPath();

		return str;
	}
}