#pragma once

#include <vector>

#include "../Controllers/iController.h"

namespace RB::Updaters
{
    class UpdaterBase
    {
    public:
        UpdaterBase() = default;
        virtual ~UpdaterBase();

    public:
        virtual void Init() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnFixedUpdate() = 0;

    public:
        virtual bool AddController(Controllers::iController* controller);

    protected:
        std::vector<Controllers::iController*> _vecControllers;
    };
}