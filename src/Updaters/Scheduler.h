#pragma once

#include <functional>

namespace RB::Updaters
{
    class Scheduler
    {
    public:
        Scheduler() = default;
        ~Scheduler() = default;

        void OnFixedUpdate()
        {
            if (_funcPtr != nullptr)
            {
                _currentFixedUpdateCount++;
            }

            if (_currentFixedUpdateCount > _totalFixedUpdates)
            {
                _funcPtr();

                _funcPtr = nullptr;
                _currentFixedUpdateCount = 0;
                _totalFixedUpdates = 0;
            }
        }

        void SetSchedule(std::function<void()> func, int totalFixedUpdates)
        {
            this->_funcPtr = func;
            _totalFixedUpdates = totalFixedUpdates;
        }

    private:
        int _currentFixedUpdateCount = 0;
        int _totalFixedUpdates = 0;
        std::function<void()> _funcPtr = nullptr;
    };
}