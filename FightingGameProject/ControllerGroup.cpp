#include "ControllerGroup.h"

namespace RB::Controllers
{
	/// <summary>
	/// Need to place the definition in the implementation (.cpp) file.
	/// </summary>
	std::vector<iController*> ControllerGroup::_vecControllers;

	void ControllerGroup::Init()
	{
		cout << "ControllerGroup::Init()" << endl;
	}

	void ControllerGroup::OnEnd()
	{
		cout << "ControllerGroup::OnEnd()" << endl;

		_DestroyAll();
	}

	void ControllerGroup::AddController(iController* newController)
	{
		if (newController != nullptr)
		{
			_vecControllers.push_back(newController);
		}
	}

	void ControllerGroup::UpdateAll()
	{
	}

	void ControllerGroup::FixedUpdateAll()
	{
	}

	void ControllerGroup::_DestroyAll()
	{
		cout << "destroying all controllers" << endl;

		for (int i = 0; i < _vecControllers.size(); i++)
		{
			//each controller should have a name string
			cout << "    " << typeid(_vecControllers[i]).name() << endl;

			delete _vecControllers[i];

			_vecControllers[i] = nullptr;
		}

		_vecControllers.clear();
	}
}