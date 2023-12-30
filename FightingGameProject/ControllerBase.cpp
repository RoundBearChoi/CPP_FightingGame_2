#include "ControllerBase.h"

namespace RB::Controllers
{
	std::vector<iController*> ControllerBase::vecControllers;

	ControllerBase::~ControllerBase()
	{
		//std::cout << "destroying controller base" << std::endl;
	}

	//template <typename T>
	//T ControllerBase::AddController(iController* controller)
	//{
	//	controller->Init();
	//
	//	vecControllers.push_back(controller);
	//
	//	return (T)controller;
	//}

	void ControllerBase::UpdateAll()
	{
		for (auto i = vecControllers.begin(); i != vecControllers.end(); i++)
		{
			(*i)->OnUpdate();
		}
	}

	void ControllerBase::FixedUpdateAll()
	{
		for (auto i = vecControllers.begin(); i != vecControllers.end(); i++)
		{
			(*i)->OnFixedUpdate();
		}
	}

	void ControllerBase::OnEnd()
	{
		for (auto i = vecControllers.begin(); i != vecControllers.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}

		vecControllers.clear();
	}
}

