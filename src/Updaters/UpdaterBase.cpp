#include "UpdaterBase.h"

namespace RB::Updaters
{
    UpdaterBase::~UpdaterBase()
    {
        for (int i = 0; i < _vecControllers.size(); i++)
        {
            delete _vecControllers[i];
            _vecControllers[i] = nullptr;
        }

        _vecControllers.clear();
    }

    bool UpdaterBase::AddController(Controllers::iController* controller)
    {
        for (int i = 0; i < _vecControllers.size(); i++)
        {
            if (_vecControllers[i]->GetControllerType() != Controllers::ControllerType::NONE)
            {
                // controller already exists
                return false;
            }
        }

        _vecControllers.push_back(controller);

        return true;
    }

    Controllers::iController* UpdaterBase::GetController(Controllers::ControllerType controllerType)
    {
        for (int i = 0; i < _vecControllers.size(); i++)
        {
            if (controllerType == _vecControllers[i]->GetControllerType())
            {
                return _vecControllers[i];
            }
        }

        return nullptr;
    }

    void UpdaterBase::_FixedUpdateControllers()
    {
        for (int i = 0; i < _vecControllers.size(); i++)
        {
            _vecControllers[i]->OnFixedUpdate();
        }
    }

    void UpdaterBase::_UpdateControllers()
    {
        for (int i = 0; i < _vecControllers.size(); i++)
        {
            _vecControllers[i]->OnUpdate();
        }
    }
}