#pragma once
#include "iInputObj.h"

namespace RB::Input
{
	class InputObj : public iInputObj
	{
	public:
		InputObj(PlayerInput playerInput, olc::Key key);
		~InputObj() override;

		void OnUpdate() override;
		void OnFixedUpdate() override;

		PlayerInput GetPlayerInput() override;
		olc::Key GetKey() override;
		void SetReleasedStatus(bool released) override;

	private:
		size_t _fixedUpdateCount = 0;
		PlayerInput _playerInput = PlayerInput::NONE;
		olc::Key _key = olc::NONE;
		bool _released = false;
	};
}