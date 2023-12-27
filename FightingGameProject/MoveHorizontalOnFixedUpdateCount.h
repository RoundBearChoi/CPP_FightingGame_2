#pragma once
#include "StateComponentBase.h"

#include "iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class MoveHorizontalOnFixedUpdateCount : public RB::States::StateComponentBase
	{
	public:
		/// <summary>
		/// positive is move forward, negative is move back
		/// </summary>
		MoveHorizontalOnFixedUpdateCount(int32_t fixedUpdateOnCount, int32_t move);
		~MoveHorizontalOnFixedUpdateCount() = default;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		int _moveAmount = 0;
		bool _otherPlayerIsOnRightSide = true;
	};
}