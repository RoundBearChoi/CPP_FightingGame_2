#include "HurtBoxDataController.h"

namespace RB::HurtBox
{
	void HurtBoxDataController::Init()
	{
		SetHash(typeid(*this));

		_loader.Init();

		//load every hurtbox dataset
		_vecDataSets.push_back(_loader.LoadDataSet("HurtBoxSpecs/Sample.HurtBoxSpecs", RB::Sprites::SpriteEnum::hurtbox_dataset_sample));
		_vecDataSets.push_back(_loader.LoadDataSet("HurtBoxSpecs/fighter_0_idle.HurtBoxSpecs", RB::Sprites::SpriteEnum::fighter_0_idle));
		_vecDataSets.push_back(_loader.LoadDataSet("HurtBoxSpecs/fighter_0_walk.HurtBoxSpecs", RB::Sprites::SpriteEnum::fighter_0_walk));

		_hurtBoxEdit.Init();
	}

	void HurtBoxDataController::OnUpdate()
	{
		_hurtBoxEdit.OnUpdate();
	}

	void HurtBoxDataController::OnFixedUpdate()
	{
		_hurtBoxEdit.OnFixedUpdate();
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