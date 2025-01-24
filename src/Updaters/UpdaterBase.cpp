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

    Controllers::iController* UpdaterBase::AddController(Controllers::iController* controller, Controllers::ControllerType controllerType)
    {
        for (int i = 0; i < _vecControllers.size(); i++)
        {
            if (_vecControllers[i]->GetControllerType() == controllerType)
            {
                // controller already exists
                return nullptr;
            }
        }

        controller->SetControllerType(controllerType);

        _vecControllers.push_back(controller);

        return controller;
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