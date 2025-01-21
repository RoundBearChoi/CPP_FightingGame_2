#pragma once

#include <vector>

#include "iUpdater.h"

#include "../Controllers/iController.h"

namespace RB::Updaters
{
    class UpdaterBase : public iUpdater
    {
    public:
        UpdaterBase() = default;
        virtual ~UpdaterBase();

    public:
        virtual void Init() = 0;
        virtual void OnFixedUpdate() = 0;
        virtual void OnUpdate() = 0;

    public:
        virtual bool AddController(Controllers::iController* controller, Controllers::ControllerType controllerType);

    public:
    template<typename T>
    T* GetController(Controllers::ControllerType controllerType);

    protected:
        virtual void _FixedUpdateControllers();
        virtual void _UpdateControllers();

    protected:
        std::vector<Controllers::iController*> _vecControllers;
    };
}