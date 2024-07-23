#pragma once

#include "PlayerInput.h"

#include "iInputObj.h"

namespace RB::Input
{
	class InputObj : public iInputObj
	{
	public:
		InputObj(PlayerInput playerInput, unsigned int gameFrame);
		~InputObj() override;

		void OnUpdate() override;
		void OnFixedUpdate() override;

		PlayerInput GetPlayerInputType() override;
		void SetReleasedStatus(bool released) override;
		void SetUsedAsSpecial(bool used) override;
		void SetUsedAsMovement(bool used) override;
		bool IsReleased() override;
		bool IsUsedAsSpecial() override;
		bool IsUsedAsMovement() override;
		unsigned int GetFixedUpdateCount() override;
		unsigned int GetGameFrameCount() override;
		bool IsPressedOnSameFrameAs(iInputObj* iObj) override;
		bool IsPressedEarlierThan(iInputObj* iObj) override;

	private:
		unsigned int _gameFrameCount = 0;
		unsigned int _fixedUpdateCount = 0;
		PlayerInput _playerInput = PlayerInput::NONE;
		bool _isReleased = false;
		bool _usedAsSpecial = false;
		bool _usedAsMovement = false;
	};
}