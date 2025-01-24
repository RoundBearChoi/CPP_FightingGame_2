#pragma once

#include <vector>

#include "iAttackSpecsController.h"

#include "../JParser.h"
#include "../Sprites/SpriteType.h"

namespace RB::Collisions
{
	class AttackSpecsController : public iAttackSpecsController
	{
	public:
		AttackSpecsController() = default;
		~AttackSpecsController() override = default;

		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

		const RB::Collisions::AttackSpecs& GetAttackSpecs(RB::Sprites::SpriteType spriteType) override;
		bool ContainsAttackSpecs(RB::Sprites::SpriteType spriteType) override;

	private:
		void _LoadAllAttackSpecs();
		void _Load(RB::Sprites::SpriteType spriteType);

	private:
		std::vector<RB::Collisions::AttackSpecs> _vecAttackSpecs;
		RB::Collisions::AttackSpecs _defaultAttackSpecs;
	};
}