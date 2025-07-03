#pragma once

#include "../enum.h"

namespace RB::Updaters
{
	BETTER_ENUM
	(
		UPDATER_TYPE, int,

		NONE = 0,
		
		GAMEPLAY_UPDATER,

		ATTACK_BOX_EDITOR_UPDATER,
		TARGET_BOX_EDITOR_UPDATER,

		COUNT
	)
}
