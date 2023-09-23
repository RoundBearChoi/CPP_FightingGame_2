#include "HB.h"

namespace RB::HBox
{
	void HB::Init()
	{
		//temp
		//_loader.InitSample("HurtBoxSpecs/Sample.HurtBoxSpecs");
		//_vecLists.push_back(_loader.LoadDataList(_dir + "Sample" + _extention, RB::Sprites::SpriteEnum::hurtbox_datalist_sample));

		//load every hurtbox datalist
		_vecLists.push_back(_loader.LoadDataList(_dir + "fighter_0_idle" + _extention, RB::Sprites::SpriteEnum::fighter_0_idle));
		_vecLists.push_back(_loader.LoadDataList(_dir + "fighter_0_walk" + _extention, RB::Sprites::SpriteEnum::fighter_0_walk));
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
}