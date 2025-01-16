#include "Scheduler.h"

namespace RB::Updaters
{
    void Scheduler::OnFixedUpdate()
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

    void Scheduler::SetSchedule(std::function<void()> func, int totalFixedUpdates)
    {
        this->_funcPtr = func;
        _totalFixedUpdates = totalFixedUpdates;
    }
}