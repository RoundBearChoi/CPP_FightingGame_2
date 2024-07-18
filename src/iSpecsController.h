#pragma once
#include "ControllerT.h"
#include "CharacterType.h"
#include "MoveSpecs.h"

namespace RB::Players::Specs
{
	class iSpecsController : public RB::Controllers::ControllerT<iSpecsController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

	public:
		virtual MoveSpecs GetMoveSpecs(RB::Players::CharacterType characterType) = 0;
	};
}