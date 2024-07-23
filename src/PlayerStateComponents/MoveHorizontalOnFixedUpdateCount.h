#pragma once

#include "../Vector2.h"
#include "../States/StateComponentBase.h"

#include "../Players/iPlayerController.h"

namespace RB::PlayerStateComponents
{
	class MoveHorizontalOnFixedUpdateCount : public RB::States::StateComponentBase
	{
	public:
		/// <summary>
		/// positive is move forward, negative is move back
		/// </summary>
		MoveHorizontalOnFixedUpdateCount(int fixedUpdateOnCount, float move);
		~MoveHorizontalOnFixedUpdateCount() = default;

	public:
		void OnEnter() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		float _moveAmount = 0.0f;
		bool _otherPlayerIsOnRightSide = true;
	};
}
