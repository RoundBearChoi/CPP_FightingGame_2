#pragma once
#include <cmath>

namespace RB::EaseEquations
{
	class Ease
	{
	public:
		static float_t EaseOutSine(float_t percentage)
		{
			return 1.0f - (sin((percentage * 3.14159265358979323846f) / 2));
		}

		static float_t EaseOutCubic(float_t percentage)
		{
			return std::pow(1.0f - percentage, 3.0f);
		}

		static float_t EaseOutQuint(float_t percentage)
		{
			return std::pow(1.0f - percentage, 5.0f);
		}

		static float_t EaseOutQuad(float_t percentage)
		{
			return ((1.0f - percentage) * (1.0f - percentage));
		}


	};
}