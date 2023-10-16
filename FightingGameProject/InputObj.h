#pragma once
#include "iInputObj.h"

namespace RB::Input
{
	class InputObj : public iInputObj
	{
	public:
		InputObj(PlayerInput playerInput);
		~InputObj() override;

		void OnUpdate() override;
		void OnFixedUpdate() override;

		PlayerInput GetPlayerInput() override;
		void SetReleasedStatus(bool released) override;
		bool IsReleased() override;

	private:
		size_t _fixedUpdateCount = 0;
		PlayerInput _playerInput = PlayerInput::NONE;
		bool _released = false;
	};
}