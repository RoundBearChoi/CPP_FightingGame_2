#include "Scheduler.h"

namespace RB
{
    void Scheduler::Init()
    {

    }

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

    void Scheduler::OnUpdate()
    {

    }

    void Scheduler::SetSchedule(void (*scheduled)(), int totalFixedUpdates)
    {
        _funcPtr = scheduled;
        _totalFixedUpdates = totalFixedUpdates;
    }
}