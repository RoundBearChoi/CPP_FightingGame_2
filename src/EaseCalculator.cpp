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

        if (_easeType == EaseType::EaseOutSine)
        {
            //_currentPercentage = Ease::EaseOutSine((float)_currentFixedUpdateCount / (float)_totalFixedUpdateCount);
        }
        else if (_easeType == EaseType::EaseInSine)
        {
            //_currentFixedUpdateCount = Ease::EaseInSine((float)_currentFixedUpdateCount / (float)_totalFixedUpdateCount);
        }

        _currentFixedUpdateCount++;
    }

    void EaseCalculator::SetTarget(int totalFixedUpdateCount, EaseType easeType, float startingPercentage, float targetPercentage)
    {
        _currentPercentage = 0.0f;
        _currentFixedUpdateCount = 0;

        _startingPercentage = startingPercentage;
        _targetPercentage = targetPercentage;
        _totalFixedUpdateCount = totalFixedUpdateCount;
        _easeType = easeType;
    }

    float EaseCalculator::GetCurrentPercentage()
    {
        return _currentPercentage;
    }
}