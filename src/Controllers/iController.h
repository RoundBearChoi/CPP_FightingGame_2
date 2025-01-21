#pragma once

#include "ControllerType.h"

namespace RB::Controllers
{
    class iController
    {
    public:
        virtual ~iController() = 0;

    public:
        virtual void Init() = 0;
        virtual void OnFixedUpdate() = 0;
        virtual void OnUpdate() = 0;
        virtual ControllerType GetControllerType() = 0;
    };
}