#include "HurtBoxDataController.h"

namespace RB::HurtBox
{
	void HurtBoxDataController::Init()
	{
		_loader.Init();

		HurtBoxData* arr = _loader.LoadData("HurtBoxData/Sample.HurtBoxData", 0);

		delete arr;
	}

	void HurtBoxDataController::OnUpdate()
	{

	}

	void HurtBoxDataController::OnFixedUpdate()
	{

	}
}