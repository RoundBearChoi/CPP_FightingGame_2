#pragma once

#include <cmath>

#include "RB_PI.h"

namespace RB
{
	enum class EaseType
    {
        NONE,

        EaseOutSine,
        EaseInSine,
		EaseOutQuad,
		EaseInQuad,
		EaseOutCubic,
		EaseInCubic,
    };

	class Ease
	{
	public:
		static float EaseOutSine(float percentage)
		{
			return 1.0f - (sin((percentage * RB_PI) / 2));
		}

		static float EaseInSine(float percentage)
		{
			return (sin((percentage * RB_PI) / 2));
		}

		static float EaseInQuad(float percentage)
		{
			return percentage * percentage;
		}

		static float EaseOutQuad(float percentage)
		{
			return 1.0f - (1.0f - percentage) * (1.0f - percentage);
		}

		static float EaseOutCubic(float percentage)
		{
			return std::pow(1.0f - percentage, 3.0f);
		}

		static float EaseInCubic(float percentage)
		{
			return std::pow(percentage, 3.0f);
		}

		static float EaseOutQuint(float percentage)
		{
			return std::pow(1.0f - percentage, 5.0f);
		}

		static float EaseInQuint(float percentage)
		{
			return std::pow(percentage, 5.0f);
		}

		static float EaseOutCirc(float percentage)
		{
			return (std::sqrt(1.0f - std::pow(percentage, 2.0f)));
		}
	};
}