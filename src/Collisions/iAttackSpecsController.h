#pragma once

#include "AttackSpecs.h"

#include "../Controllers/ControllerT.h"
#include "../Sprites/SpriteType.h"

namespace RB::Collisions
{
	class iAttackSpecsController : public Controllers::ControllerT<iAttackSpecsController>
	{
	public:
		virtual void Init() = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		const virtual Collisions::AttackSpecs& GetAttackSpecs(Sprites::SpriteType spriteType) = 0;
		virtual bool ContainsAttackSpecs(Sprites::SpriteType spriteType) = 0;
	};
}