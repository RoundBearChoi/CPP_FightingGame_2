#pragma once

#include "CharacterType.h"
#include "MoveSpecs.h"

#include "../Controllers/ControllerBase.h"

namespace RB::Players
{
	#define GET_SPECS_CONTROLLER static_cast<RB::Players::iSpecsController*>(RB::Controllers::GetController(Controllers::ControllerType::SPECS_CONTROLLER))

	class iSpecsController : public RB::Controllers::ControllerBase
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

	public:
		virtual MoveSpecs GetMoveSpecs(RB::Players::CharacterType characterType) = 0;
	};
}