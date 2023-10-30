#pragma once
#include <cmath>

namespace RB::Equations
{
	class Ease
	{
	public:
		/// <summary>
		/// total is 1
		/// </summary>
		static float_t EaseOutQuint(float_t progress)
		{
			return 1.0f - std::pow(1.0f - progress, 5.0f);
		}
	};
}