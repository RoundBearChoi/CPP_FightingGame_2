#pragma once

#include "../InfInt.h"

#include "PlayerInput.h"

#include "iInputObj.h"

namespace RB::Input
{
	class InputObj : public iInputObj
	{
	public:
		InputObj(PlayerInput playerInput, InfInt gameFrame);
		~InputObj() override;

		void OnUpdate() override;
		void OnFixedUpdate() override;

		PlayerInput GetPlayerInputType() override;
		void SetReleasedStatus(bool released) override;
		void SetUsedAsAttack(bool used) override;
		void SetUsedAsMovement(bool used) override;
		bool IsReleased() override;
		bool IsUsedAsAttack() override;
		bool IsUsedAsMovement() override;
		unsigned int GetFixedUpdateCount() override;
		InfInt GetGameFrameCount() override;
		bool IsPressedOnSameFrameAs(iInputObj* iObj) override;
		bool IsPressedEarlierThan(iInputObj* iObj) override;

	private:
		InfInt _gameFrameCount = 0;
		unsigned int _fixedUpdateCount = 0;
		PlayerInput _playerInput = PlayerInput::NONE;
		bool _isReleased = false;
		bool _usedAsAttack = false;
		bool _usedAsMovement = false;
	};
}
