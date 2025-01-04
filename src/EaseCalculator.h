#pragma once

namespace RB
{
    class EaseCalculator
    {
    public:
        void Init();
        void OnUpdate();
        void OnFixedUpdate();

    private:
        float _currentPercentage = 0.0f;
        float _targetPercentage = 0.0f;
    };
}