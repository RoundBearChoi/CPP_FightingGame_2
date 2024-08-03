#pragma once

#include <vector>

#include "CustomRenderBase.h"

namespace RB::Render
{
    template <typename T, typename = std::enable_if_t<std::is_base_of<CustomRenderBase, T>::value>>
    class CustomRenderContainer
    {
    public:
        ~CustomRenderContainer()
        {
            for (auto obj : _vec)
            {
                delete obj;
            }

            _vec.clear();
        }

        void OnFixedUpdate()
        {
            // update one at a time
            if (_vec.size() >= 1)
            {
                _vec[0]->SetStart(_lastAmount);
            
                _vec[0]->OnFixedUpdate();
                _vec[0]->AddProcessedFrame();
            
                if (_vec[0]->DoDelete())
                {
                    delete _vec[0];
                    _vec.erase(_vec.begin());
                }
            }
        }

    public:
        /// Adds an object to the container.
        /// The object will be deleted by the class destructor.
        void AddObj(CustomRenderBase* obj)
        {
            _vec.push_back(obj);
        }

    protected:
        std::vector<T*> _vec;
        float _lastAmount = 0.0f;
    };
}
