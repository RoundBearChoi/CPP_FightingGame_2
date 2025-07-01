#pragma once

#include "../enum.h"

namespace RB::Log
{
	BETTER_ENUM
	(
		LOG_TYPE, int,

		NONE = 0,

		INPUT,
		
		LOAD_SPRITE,
		LOAD_JSON,

		PLAYER_STATE,

		COUNT
	)
}
