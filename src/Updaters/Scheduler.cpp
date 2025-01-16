#include "Scheduler.h"

namespace RB::Updaters
{
    void Scheduler::OnFixedUpdate()
    {
        if (_func != nullptr)
        {
            _currentFixedUpdateCount++;
        }

        if (_currentFixedUpdateCount > _totalFixedUpdates)
        {
            _func();

            _func = nullptr;
            _currentFixedUpdateCount = 0;
            _totalFixedUpdates = 0;
        }
    }

    void Scheduler::SetSchedule(std::function<void()> func, int totalFixedUpdates)
    {
        this->_func = func;
        _totalFixedUpdates = totalFixedUpdates;
    }
}