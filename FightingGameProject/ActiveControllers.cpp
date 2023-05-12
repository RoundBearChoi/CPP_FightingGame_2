#include "ActiveControllers.h"

namespace RB::Controllers
{
	void ActiveControllers::Init()
	{

	}

	void ActiveControllers::OnEnd()
	{
		_DestroyAll();
	}

	void ActiveControllers::AddController(iController* newController)
	{
		if (newController != nullptr)
		{
			newController->Init();

			_vecControllers.push_back(newController);
		}
	}

	void ActiveControllers::UpdateAll()
	{
		for (int i = 0; i < _vecControllers.size(); i++)
		{
			_vecControllers[i]->OnUpdate();
		}
	}

	void ActiveControllers::FixedUpdateAll()
	{
		for (int i = 0; i < _vecControllers.size(); i++)
		{
			_vecControllers[i]->OnFixedUpdate();
		}
	}

	void ActiveControllers::_DestroyAll()
	{
		for (int i = 0; i < _vecControllers.size(); i++)
		{
			delete _vecControllers[i];

			_vecControllers[i] = nullptr;
		}

		_vecControllers.clear();
	}
}