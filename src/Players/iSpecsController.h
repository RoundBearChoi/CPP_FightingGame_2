#pragma once

#include "CharacterType.h"
#include "MoveSpecs.h"

#include "../Controllers/ControllerBase.h"

namespace RB::Players
{
	#define GET_SPECS_CONTROLLER static_cast<Players::iSpecsController*>(Controllers::GetController(Controllers::ControllerType::SPECS_CONTROLLER))

	class iSpecsController : public Controllers::ControllerBase
	{
	public:
		virtual MoveSpecs GetMoveSpecs(Players::CharacterType characterType) = 0;
	};
}
