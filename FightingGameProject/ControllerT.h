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
            return _instance;
        }

        ControllerT()
        {
            _instance = static_cast<T*>(this);
        }

        ~ControllerT() override
        {
            _instance = nullptr;
        }

    private:
        static T* _instance;
    };

    template <class T> T* ControllerT<T>::_instance = nullptr;
}