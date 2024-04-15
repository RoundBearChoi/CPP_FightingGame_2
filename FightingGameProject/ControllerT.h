#pragma once

#include "ControllerBase.h"

namespace RB::Controllers
{
    template <class T>
    class ControllerT : public ControllerBase
    {
    public:
        static T* Get()
        {
            return instance;
        }

        ControllerT()
        {
            instance = static_cast<T*>(this);

            //std::cout << "controller created" << std::endl;
        }

        ~ControllerT() override
        {
            instance = nullptr;
        }

    private:
        static T* instance;
    };



    template <class T> T* ControllerT<T>::instance = nullptr;
}