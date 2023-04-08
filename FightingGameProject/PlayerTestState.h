#pragma once
#include "StateBase.h"

using namespace RB::States;

namespace RB::Players
{
	class PlayerTestState : public StateBase
	{
	public:
		~PlayerTestState() override;

		void OnFixedUpdate() override;
	};
}