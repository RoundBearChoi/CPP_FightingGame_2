#pragma once

#include <vector>

#include "iUpdater.h"

namespace RB::Updaters
{
    class UpdaterBase : public iUpdater
    {
    public:
        UpdaterBase() = default;
        virtual ~UpdaterBase();

    public:
        virtual void Init() override {}
        virtual void OnFixedUpdate() override {}
        virtual void OnUpdate() override {}

    public:
        virtual Controllers::iController* AddController(Controllers::iController* controller, Controllers::ControllerType controllerType) override;
        virtual Controllers::iController* GetController(Controllers::ControllerType controllerType) override;

    protected:
        virtual void _FixedUpdateControllers();
        virtual void _UpdateControllers();

    protected:
        std::vector<Controllers::iController*> _vecControllers;
    };
}