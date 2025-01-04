#include "EaseCalculator.h"

namespace RB
{
    void EaseCalculator::Init()
    {

    }

    void EaseCalculator::OnUpdate()
    {

    }

    void EaseCalculator::OnFixedUpdate()
    {
        if (std::abs(_currentPercentage - _targetPercentage) <= 0.0001f)
        {
            return;
        }

        
    }

    void EaseCalculator::SetTarget(int totalFixedUpdateCount, EaseType easeType)
    {
        _totalFixedUpdateCount = totalFixedUpdateCount;
        _easeType = easeType;
    }
}