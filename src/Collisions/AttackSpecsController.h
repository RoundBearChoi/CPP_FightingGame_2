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

		const Collisions::AttackSpecs& GetAttackSpecs(Sprites::SpriteType spriteType) override;
		bool ContainsAttackSpecs(Sprites::SpriteType spriteType) override;

	private:
		void _LoadAllAttackSpecs();
		void _Load(Sprites::SpriteType spriteType);

	private:
		std::vector<Collisions::AttackSpecs> _vecAttackSpecs;
		Collisions::AttackSpecs _defaultAttackSpecs;
	};
}