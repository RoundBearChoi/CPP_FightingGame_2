#include "HurtBoxDataController.h"

namespace RB::HurtBox
{
	HurtBoxDataController::~HurtBoxDataController()
	{
		for (size_t i = 0; i < _vecData.size(); i++)
		{
			delete[] _vecData[i];
		}
	}

	void HurtBoxDataController::Init()
	{
		_loader.Init();

		HurtBoxData* arr = _loader.LoadData("HurtBoxData/Sample.HurtBoxData", 0);

		_vecData.push_back(arr);
	}

	void HurtBoxDataController::OnUpdate()
	{

	}

	void HurtBoxDataController::OnFixedUpdate()
	{

	}
}