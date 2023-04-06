#include "ControllerGroup.h"

namespace RB::Controllers
{
	std::vector<iController> ControllerGroup::_vecControllers;
	std::vector<int> ControllerGroup::_test;

	void ControllerGroup::Init()
	{
		cout << "ControllerGroup::Init()" << endl;

		cout << &_vecControllers << endl;
		cout << &_test << endl;

		_test.push_back(1);
	}

	void ControllerGroup::OnEnd()
	{
		cout << "ControllerGroup::OnEnd()" << endl;
	}
}