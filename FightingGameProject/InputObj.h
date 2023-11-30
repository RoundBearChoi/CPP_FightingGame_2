#pragma once
#include "iInputObj.h"

namespace RB::Input
{
	class InputObj : public iInputObj
	{
	public:
		InputObj(PlayerInput playerInput, size_t gameFrame, size_t gameFrameLoop);
		~InputObj() override;

		void OnUpdate() override;
		void OnFixedUpdate() override;

		PlayerInput GetPlayerInputType() override;
		void SetReleasedStatus(bool released) override;
		void SetUsedStatus(bool used) override;
		bool IsReleased() override;
		bool IsUsed() override;
		size_t GetFixedUpdateCount() override;
		size_t GetGameFrameCount() override;
		size_t GetGameFrameLoopCount() override;
		bool IsPressedOnSameFrameAs(iInputObj* iObj) override;
		bool IsPressedEarlierThan(iInputObj* iObj) override;

	private:
		size_t _gameFrameCount = 0;
		size_t _gameFrameLoopCount = 0;
		size_t _fixedUpdateCount = 0;
		PlayerInput _playerInput = PlayerInput::NONE;
		bool _isReleased = false;
		bool _isUsed = false;
	};
}