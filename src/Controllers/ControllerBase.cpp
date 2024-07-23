#include "ControllerBase.h"

namespace RB::Controllers
{
	std::vector<ControllerBase*> ControllerBase::vecControllers;

	void ControllerBase::UpdateAll()
	{
		for (auto i = vecControllers.begin(); i != vecControllers.end(); i++)
		{
			(*i)->OnUpdate();

			// reset to default after drawing on custom layer
			olc::Renderer::ptrPGE->SetDrawTarget(nullptr);
		}
	}

	void ControllerBase::FixedUpdateAll()
	{
		for (auto i = vecControllers.begin(); i != vecControllers.end(); i++)
		{
			(*i)->OnFixedUpdate();
		}
	}

	void ControllerBase::DestroyAllControllers()
	{
		for (auto i = vecControllers.begin(); i != vecControllers.end(); i++)
		{
			delete (*i);
			(*i) = nullptr;
		}

		vecControllers.clear();
	}
}
