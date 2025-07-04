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
        else if (_easeType == EaseType::EaseOutQuad)
        {
            eased = Ease::EaseOutQuad(progress);
        }
        else if (_easeType == EaseType::EaseInQuad)
        {
            eased = Ease::EaseInQuad(progress);
        }
        else if (_easeType == EaseType::EaseOutCubic)
        {
            eased = Ease::EaseOutCubic(progress);
        }
        else if (_easeType == EaseType::EaseInCubic)
        {
            eased = Ease::EaseInCubic(progress);
        }
        else
        {
            return;
        }

        if (eased >= 1.0f)
        {
            eased = 1.0f;
        }
        else if (eased <= 0.0f)
        {
            eased = 0.0f;
        }
        else
        {

        }
        
        _currentPercentage = _startingPercentage + (eased * (_targetPercentage - _startingPercentage));

        _currentFixedUpdateCount++;
    }

    void EaseCalculator::SetTarget(int totalFixedUpdateCount, EaseType easeType, float startingPercentage, float targetPercentage)
    {
        _currentFixedUpdateCount = 0;

        _startingPercentage = startingPercentage;
        _targetPercentage = targetPercentage;
        _totalFixedUpdateCount = totalFixedUpdateCount;
        _easeType = easeType;
    }

    void EaseCalculator::ClearTarget()
    {
        _currentFixedUpdateCount = 0;
        _startingPercentage = 0.0f;
        _targetPercentage = 0.0f;
        _totalFixedUpdateCount = 0;
        _easeType = EaseType::NONE;
    }

    float EaseCalculator::GetCurrentPercentage()
    {
        return _currentPercentage;
    }

    int EaseCalculator::GetCurrentFixedUpdateCount()
    {
        return _currentFixedUpdateCount;
    }

    int EaseCalculator::GetRemainingFixedUpdateCount()
    {
        int r =  _totalFixedUpdateCount - _currentFixedUpdateCount;

        if (r < 0)
        {
            r = 0;
        }

        return r;
    }

    EaseType EaseCalculator::GetEaseType()
    {
        return _easeType;
    }

    float EaseCalculator::GetTargetPercentage()
    {
        return _targetPercentage;
    }
}
