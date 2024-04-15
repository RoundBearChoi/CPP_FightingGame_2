#include "ControllerBase.h"

namespace RB::Controllers
{
	std::vector<ControllerBase*> ControllerBase::vecControllers;

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
		DeleteAllControllers();
	}

	void ControllerBase::DeleteAllControllers()
	{
		for (auto i = vecControllers.begin(); i != vecControllers.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}

		vecControllers.clear();
	}
}