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

    // Definition of the pure virtual destructor
    // The purpose of having an interface (abstract base class) in C++ is to define a contract for derived classes, ensuring they implement specific functions. The pure virtual destructor is a bit of an exception. Even though it requires a definition, it doesn't undermine the purpose of the interface.
    // The pure virtual destructor ensures that the base class destructor is called when an object of a derived class is destroyed. This is crucial for proper resource management and cleanup. Without it, you might run into issues where the base class resources are not properly released.
    // While it might seem counterintuitive to provide a definition for a pure virtual destructor, it's a necessary step to ensure the correct destruction order and resource management. The interface still serves its primary purpose of defining a contract for derived classes.
    inline iController::~iController() {}
}