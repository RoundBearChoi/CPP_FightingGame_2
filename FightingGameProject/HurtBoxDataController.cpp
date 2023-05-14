#include "HurtBoxDataController.h"

namespace RB::HurtBox
{
	void HurtBoxDataController::Init()
	{
		_loader.Init();

		_vecDataSets.push_back(_loader.LoadDataSet("HurtBoxSpecs/Sample.HurtBoxSpecs", RB::Sprites::SpriteID::hurtbox_dataset_sample));
		_vecDataSets.push_back(_loader.LoadDataSet("HurtBoxSpecs/fighter_0_idle.HurtBoxSpecs", RB::Sprites::SpriteID::fighter_0_idle));
	}

	void HurtBoxDataController::OnUpdate()
	{

	}

	void HurtBoxDataController::OnFixedUpdate()
	{

	}
}