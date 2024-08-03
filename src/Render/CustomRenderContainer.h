#pragma once

#include <vector>

#include "CustomRender.h"

namespace RB::Render
{
    template <typename T, typename = std::enable_if_t<std::is_base_of<CustomRender, T>::value>>
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
        /// Adds an object (CustomRenderBase) to the container.
        /// The object will be deleted by the class destructor.
        void AddObj(T* obj)
        {
            _vec.push_back(obj);
        }

        void SetLastAmount(float amount)
        {
            _lastAmount = amount;
        }

        float GetAmount()
        {
            if (_vec.size() == 0)
            {
                return _lastAmount;
            }
            else if (_vec[0]->GetProcessedFrameCount() == 0)
            {
                return _lastAmount;
            }
            else
            {
                float m = _vec[0]->GetAmount();

                _lastAmount = m;

                return m;
            }
        }

    protected:
        std::vector<T*> _vec;
        float _lastAmount = 0.0f;
    };
}
