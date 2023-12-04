#include "ControllerBase.h"

namespace RB::Controllers
{
	std::vector<iController*> ControllerBase::vecControllers;

	void ControllerBase::AddController(iController* controller)
	{
		controller->Init();

		vecControllers.push_back(controller);
	}

	void ControllerBase::UpdateAll()
	{
		for (size_t i = 0; i < vecControllers.size(); i++)
		{
			vecControllers[i]->OnUpdate();
		}
	}

	void ControllerBase::FixedUpdateAll()
	{
		for (size_t i = 0; i < vecControllers.size(); i++)
		{
			vecControllers[i]->OnFixedUpdate();
		}
	}

	void ControllerBase::OnEnd()
	{
		for (size_t i = 0; i < vecControllers.size(); i++)
		{
			delete vecControllers[i];
			vecControllers[i] = nullptr;
		}

		vecControllers.clear();
	}

	//void ControllerBase::SetHash(const type_info& ti)
	//{
	//	std::string name = ti.name();
	//
	//	std::hash<std::string> hasher;
	//
	//	_hash = hasher(name);
	//}
	//
	//size_t ControllerBase::GetHash()
	//{
	//	return _hash;
	//}
}