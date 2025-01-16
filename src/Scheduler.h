#pragma once

namespace RB
{
    class Scheduler
    {
    public:
        Scheduler() = default;
        ~Scheduler() = default;

        void Init();
        void OnFixedUpdate();
        void OnUpdate();
        void SetSchedule(void (*scheduled)(), int totalFixedUpdates);

    private:
        int _currentFixedUpdateCount = 0;
        int _totalFixedUpdates = 0;
        void (*_funcPtr)() = nullptr;
    };
}