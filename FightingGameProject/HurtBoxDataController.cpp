#include "HurtBoxDataController.h"

namespace RB::HurtBox
{
	void HurtBoxDataController::Init()
	{
		_loader.Init();

		std::vector<HurtBoxData> vec = _loader.LoadData("HurtBoxData/Sample.HurtBoxData", 2);
	}

	void HurtBoxDataController::OnUpdate()
	{

	}

	void HurtBoxDataController::OnFixedUpdate()
	{

	}
}