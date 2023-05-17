#include "HurtBoxDataSet.h"

namespace RB::HurtBox
{
	HurtBoxDataSet::HurtBoxDataSet(RB::Sprites::SpriteEnum spriteEnum)
	{
		_spriteEnum = spriteEnum;
	}

	void HurtBoxDataSet::AddHurtBoxData(HurtBoxData data)
	{
		_vecHurtBoxData.push_back(data);
	}
	RB::Sprites::SpriteEnum HurtBoxDataSet::GetSpriteEnum()
	{
		return _spriteEnum;
	}
}