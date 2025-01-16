#pragma once

#include <functional>

namespace RB::Updaters
{
    class Scheduler
    {
    public:
        Scheduler() = default;
        ~Scheduler() = default;

        void OnFixedUpdate();
        void SetSchedule(std::function<void()> func, int totalFixedUpdates);

    private:
        int _currentFixedUpdateCount = 0;
        int _totalFixedUpdates = 0;
        std::function<void()> _funcPtr = nullptr;
    };
}