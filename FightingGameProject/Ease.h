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
		static float EaseOutQuint(float_t progress)
		{
			return 1 - std::pow(1 - progress, 5);
		}
	};
}