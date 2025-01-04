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

        float progress = (float)_currentFixedUpdateCount / (float)_totalFixedUpdateCount;
        float eased = 0.0f;

        if (_easeType == EaseType::EaseOutSine)
        {
            eased  = Ease::EaseOutSine(progress);
        }
        else if (_easeType == EaseType::EaseInSine)
        {
            eased  = Ease::EaseInSine(progress);
        }

        float insidePercentage = (_currentPercentage - _startingPercentage) / (_targetPercentage - _startingPercentage);
        float result = insidePercentage * eased;

        _currentPercentage = _startingPercentage + result;

        _currentFixedUpdateCount++;
    }

    void EaseCalculator::SetTarget(int totalFixedUpdateCount, EaseType easeType, float startingPercentage, float targetPercentage)
    {
        //_currentPercentage = 0.0f;
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