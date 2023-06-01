#include "HurtBoxDataController.h"

namespace RB::HBox
{
	void HurtBoxDataController::Init()
	{
		SetHash(typeid(*this));

		_loader.Init();

		//load every hurtbox dataset
		_vecDataSets.push_back(_loader.LoadDataSet("HurtBoxSpecs/Sample.HurtBoxSpecs", RB::Sprites::SpriteEnum::hurtbox_dataset_sample));
		_vecDataSets.push_back(_loader.LoadDataSet("HurtBoxSpecs/fighter_0_idle.HurtBoxSpecs", RB::Sprites::SpriteEnum::fighter_0_idle));
		_vecDataSets.push_back(_loader.LoadDataSet("HurtBoxSpecs/fighter_0_walk.HurtBoxSpecs", RB::Sprites::SpriteEnum::fighter_0_walk));
	}

	void HurtBoxDataController::OnUpdate()
	{

	}

	void HurtBoxDataController::OnFixedUpdate()
	{

	}

	HBoxDataSet* HurtBoxDataController::GetDataSet(RB::Sprites::SpriteEnum spriteEnum)
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

	const std::string& HurtBoxDataController::GetPath(RB::Sprites::SpriteEnum spriteEnum)
	{
		HurtBoxDataSetPath* p = _loader.GetDataSetPath(spriteEnum);

		if (p != nullptr)
		{
			return p->GetPath();
		}

		return _none;
	}
}