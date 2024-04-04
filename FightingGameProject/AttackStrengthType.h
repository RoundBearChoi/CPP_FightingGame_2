#pragma once

#include "enum.h"

namespace RB::Collisions
{
	BETTER_ENUM
	{
		AttackStrengthType, int,

		NONE = 0,

		WEAK,
		STRONG,

		COUNT
	};
}