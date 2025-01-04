#pragma once

#include <cmath>
#include <iostream>

#include "Ease.h"

namespace RB
{
    class EaseCalculator
    {
    public:
        void Init();
        void OnUpdate();
        void OnFixedUpdate();

        void SetTarget(int totalFixedUpdateCount, EaseType easeType, float startingPercentage, float targetPercentage);
        void ClearTarget();
        float GetCurrentPercentage();
        int GetCurrentFixedUpdateCount();
        EaseType GetEaseType();
        float GetTargetPercentage();

    private:
        EaseType _easeType = EaseType::NONE;
        float _startingPercentage = 0.0f;
        float _currentPercentage = 0.0f;
        float _targetPercentage = 0.0f;
        int _totalFixedUpdateCount = 0;
        int _currentFixedUpdateCount = 0;
    };
}