#pragma once
#include "StateComponentBase.h"

namespace RB::PlayerStateComponents
{
	class KeepMovingForward : public RB::States::StateComponentBase
	{
	public:
		KeepMovingForward();
		~KeepMovingForward() override;

	public:
		void OnUpdate() override;
	};
}