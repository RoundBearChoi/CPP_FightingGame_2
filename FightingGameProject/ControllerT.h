#pragma once

#include "ControllerBase.h"

namespace RB::Controllers
{
    template <class T>
    class ControllerT : public ControllerBase
    {
    public:
        static T* instance;

        ControllerT()
        {
            instance = static_cast<T*>(this);

            //std::cout << "controller created" << std::endl;
        }

        ~ControllerT() override
        {
            instance = nullptr;
        }
    };

    template <class T> T* ControllerT<T>::instance = nullptr;
}