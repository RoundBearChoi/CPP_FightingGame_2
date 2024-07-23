#pragma once

#include "../StateComponentBase.h"

#include "../Players/iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class MarkInitiallyFacingRight : public RB::States::StateComponentBase
	{
	public:
		MarkInitiallyFacingRight() = default;
		~MarkInitiallyFacingRight() override = default;

		void OnEnter() override;

	private:
		bool _facingRight = true;
	};
}
