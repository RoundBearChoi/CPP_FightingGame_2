#pragma once

#include <cmath>

#include "Ease.h"

namespace RB
{
    class EaseCalculator
    {
    public:
        void Init();
        void OnUpdate();
        void OnFixedUpdate();

        void SetTarget(int totalFixedUpdateCount, EaseType easeType);

    private:
        EaseType _easeType = EaseType::NONE;
        float _currentPercentage = 0.0f;
        float _targetPercentage = 0.0f;
        int _totalFixedUpdateCount = 0;
    };
}