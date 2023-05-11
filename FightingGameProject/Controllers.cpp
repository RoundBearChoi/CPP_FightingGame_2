#include "Controllers.h"

namespace RB::Controllers
{
	void Controllers::Init()
	{

	}

	void Controllers::OnEnd()
	{
		_DestroyAll();
	}

	void Controllers::AddController(iController* newController)
	{
		if (newController != nullptr)
		{
			newController->Init();

			_vecControllers.push_back(newController);
		}
	}

	void Controllers::UpdateAll()
	{
		for (int i = 0; i < _vecControllers.size(); i++)
		{
			_vecControllers[i]->OnUpdate();
		}
	}

	void Controllers::FixedUpdateAll()
	{
		for (int i = 0; i < _vecControllers.size(); i++)
		{
			_vecControllers[i]->OnFixedUpdate();
		}
	}

	void Controllers::_DestroyAll()
	{
		for (int i = 0; i < _vecControllers.size(); i++)
		{
			delete _vecControllers[i];

			_vecControllers[i] = nullptr;
		}

		_vecControllers.clear();
	}
}