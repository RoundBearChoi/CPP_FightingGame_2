#pragma once

#include "AttackSpecs.h"

#include "../Controllers/ControllerT.h"
#include "../Sprites/SpriteType.h"

namespace RB::Collisions
{
	class iAttackSpecsController : public RB::Controllers::ControllerT<iAttackSpecsController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		const virtual RB::Collisions::AttackSpecs& GetAttackSpecs(RB::Sprites::SpriteType spriteType) = 0;
		virtual bool ContainsAttackSpecs(RB::Sprites::SpriteType spriteType) = 0;
	};
}
