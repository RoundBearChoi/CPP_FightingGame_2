#pragma once

#include <cmath>

namespace RB
{
	class Ease
	{
	public:
		static float EaseOutSine(float percentage)
		{
			return 1.0f - (sin((percentage * 3.14159265358979323846f) / 2));
		}

		static float EaseOutCubic(float percentage)
		{
			return std::pow(1.0f - percentage, 3.0f);
		}

		static float EaseOutQuint(float percentage)
		{
			return std::pow(1.0f - percentage, 5.0f);
		}

		static float EaseOutQuad(float percentage)
		{
			return ((1.0f - percentage) * (1.0f - percentage));
		}

		static float EaseOutCirc(float percentage)
		{
			return (std::sqrt(1.0f - std::pow(percentage, 2.0f)));
		}
	};
}
