#pragma once

#include "iSpecsController.h"

#include "JGetter.h"

namespace RB::Players::Specs
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
		void _SaveMoveSpecs(std::string path, MoveSpecs specs);
		MoveSpecs _LoadMoveSpecs(std::string path);
	};
}