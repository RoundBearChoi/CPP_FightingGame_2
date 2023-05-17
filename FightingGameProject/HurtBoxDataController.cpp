#include "HurtBoxDataController.h"

namespace RB::HurtBox
{
	void HurtBoxDataController::Init()
	{
		SetHash(typeid(*this));

		_loader.Init();

		_vecDataSets.push_back(_loader.LoadDataSet("HurtBoxSpecs/Sample.HurtBoxSpecs", RB::Sprites::SpriteEnum::hurtbox_dataset_sample));
		_vecDataSets.push_back(_loader.LoadDataSet("HurtBoxSpecs/fighter_0_idle.HurtBoxSpecs", RB::Sprites::SpriteEnum::fighter_0_idle));
	}

	void HurtBoxDataController::OnUpdate()
	{
		
	}

	void HurtBoxDataController::OnFixedUpdate()
	{

	}

	HurtBoxDataSet* HurtBoxDataController::GetDataSet(RB::Sprites::SpriteEnum spriteEnum)
	{
		for (size_t i = 0; i < _vecDataSets.size(); i++)
		{
			if (_vecDataSets[i].GetSpriteEnum() == spriteEnum)
			{
				return &_vecDataSets[i];
			}
		}

		return nullptr;
	}
}