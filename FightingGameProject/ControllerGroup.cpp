#include "ControllerGroup.h"

namespace RB::Controllers
{
	void ControllerGroup::Init()
	{
		//cout << "ControllerGroup::Init()" << endl;
	}

	void ControllerGroup::OnEnd()
	{
		//cout << "ControllerGroup::OnEnd()" << endl;

		_DestroyAll();
	}

	void ControllerGroup::AddController(iController* newController)
	{
		if (newController != nullptr)
		{
			newController->Init();

			_vecControllers.push_back(newController);
		}
	}

	void ControllerGroup::UpdateAll()
	{
		for (int i = 0; i < _vecControllers.size(); i++)
		{
			_vecControllers[i]->OnUpdate();
		}
	}

	void ControllerGroup::FixedUpdateAll()
	{
		for (int i = 0; i < _vecControllers.size(); i++)
		{
			_vecControllers[i]->OnFixedUpdate();
		}
	}

	void ControllerGroup::_DestroyAll()
	{
		//cout << "destroying all controllers" << endl;

		for (int i = 0; i < _vecControllers.size(); i++)
		{
			delete _vecControllers[i];

			_vecControllers[i] = nullptr;
		}

		_vecControllers.clear();
	}
}