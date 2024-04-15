#pragma once
//#include <iostream>

#include "ControllerBase.h"

namespace RB::Controllers
{
    template <class T>
    class ControllerT : public ControllerBase
    {
    public:
        static T* Get()
        {
            if (instance == nullptr)
            {
                //std::cout << "creating new controller" << std::endl;
            }

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