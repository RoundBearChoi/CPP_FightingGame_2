#pragma once

#include <vector>
#include <string>
#include <iostream>

#include "CharacterType.h"

#include "iSpecsController.h"

#include "../JParser.h"
#include "../MoveSpecs.h"

namespace RB::Players
{
	class SpecsController : public iSpecsController
	{
	public:
		SpecsController() = default;
		~SpecsController() override;

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		MoveSpecs GetMoveSpecs(RB::Players::CharacterType characterType) override;

	private:
		MoveSpecs _LoadMoveSpecs(std::string path, RB::Players::CharacterType characterType);
		std::vector<MoveSpecs> _vecMoveSpecs;
	};
}
