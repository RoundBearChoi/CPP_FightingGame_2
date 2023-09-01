#include "HB.h"

namespace RB::HBox
{
	void HB::Init()
	{
		//temp
		_loader.InitSample("HurtBoxSpecs/Sample.HurtBoxSpecs");

		//temp - load every hurtbox datalist
		_vecLists.push_back(_loader.LoadDataList("HurtBoxSpecs/Sample.HurtBoxSpecs", RB::Sprites::SpriteEnum::hurtbox_datalist_sample));
		_vecLists.push_back(_loader.LoadDataList("HurtBoxSpecs/fighter_0_idle.HurtBoxSpecs", RB::Sprites::SpriteEnum::fighter_0_idle));
		_vecLists.push_back(_loader.LoadDataList("HurtBoxSpecs/fighter_0_walk.HurtBoxSpecs", RB::Sprites::SpriteEnum::fighter_0_walk));
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