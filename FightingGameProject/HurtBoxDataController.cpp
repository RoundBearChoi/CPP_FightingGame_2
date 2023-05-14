#include "HurtBoxDataController.h"

namespace RB::HurtBox
{
	void HurtBoxDataController::Init()
	{
		_loader.Init();

		_vecDataSets.push_back(_loader.LoadDataSet("HurtBoxSpecs/Sample.HurtBoxSpecs", RB::Sprites::SpriteID::NONE));
		_vecDataSets.push_back(_loader.LoadDataSet("HurtBoxSpecs/Sample.HurtBoxSpecs", RB::Sprites::SpriteID::fighter_0_idle));
	}

	void HurtBoxDataController::OnUpdate()
	{

	}

	void HurtBoxDataController::OnFixedUpdate()
	{

	}
}