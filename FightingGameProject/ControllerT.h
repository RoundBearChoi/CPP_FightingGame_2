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
            if (_instance == nullptr)
            {
                //std::cout << "creating new controller" << std::endl;
            }

            return _instance;
        }

        ControllerT()
        {
            _instance = static_cast<T*>(this);

            //std::cout << "controller created" << std::endl;
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