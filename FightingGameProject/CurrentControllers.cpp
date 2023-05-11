#include "CurrentControllers.h"

namespace RB::Controllers
{
	void CurrentControllers::Init()
	{

	}

	void CurrentControllers::OnEnd()
	{
		_DestroyAll();
	}

	void CurrentControllers::AddController(iController* newController)
	{
		if (newController != nullptr)
		{
			newController->Init();

			_vecControllers.push_back(newController);
		}
	}

	iController* CurrentControllers::GetController(const std::type_info& ti)
	{
		std::string name = ti.name();

		std::hash<std::string> hasher;

		size_t hash = hasher(name);

		for (int i = 0; i < _vecControllers.size(); i++)
		{
			if (_vecControllers[i]->GetHash() == hash)
			{
				return _vecControllers[i];
			}
		}

		return nullptr;
	}

	void CurrentControllers::UpdateAll()
	{
		for (int i = 0; i < _vecControllers.size(); i++)
		{
			_vecControllers[i]->OnUpdate();
		}
	}

	void CurrentControllers::FixedUpdateAll()
	{
		for (int i = 0; i < _vecControllers.size(); i++)
		{
			_vecControllers[i]->OnFixedUpdate();
		}
	}

	void CurrentControllers::_DestroyAll()
	{
		for (int i = 0; i < _vecControllers.size(); i++)
		{
			delete _vecControllers[i];

			_vecControllers[i] = nullptr;
		}

		_vecControllers.clear();
	}
}