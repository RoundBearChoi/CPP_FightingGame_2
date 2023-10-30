#pragma once
#include <cmath>

namespace RB::EaseEquations
{
	class Ease
	{
	public:
		static float_t EaseOutQuint(float_t progress)
		{
			return /*1.0f -*/ std::pow(1.0f - progress, 5.0f);
		}

		static float_t EaseOutQuad(float_t progress)
		{
			return /*1.0f -*/ ((1.0f - progress) * (1.0f - progress));
		}
	};
}