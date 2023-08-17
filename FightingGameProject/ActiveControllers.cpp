#include "ActiveControllers.h"

namespace RB::Controllers
{
	void ActiveControllers::OnEnd()
	{
		_DestroyAll();
	}

	/// <summary>
	/// adding also initializes
	/// </summary>
	/// <param name="newController"></param>
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
		for (size_t i = 0; i < _vecControllers.size(); i++)
		{
			_vecControllers[i]->OnUpdate();
		}
	}

	void ActiveControllers::FixedUpdateAll()
	{
		for (size_t i = 0; i < _vecControllers.size(); i++)
		{
			_vecControllers[i]->OnFixedUpdate();
		}
	}

	void ActiveControllers::_DestroyAll()
	{
		for (size_t i = 0; i < _vecControllers.size(); i++)
		{
			delete _vecControllers[i];
		}

		_vecControllers.clear();
	}
}