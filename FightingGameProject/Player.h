#pragma once
#include "olcPixelGameEngine.h"
#include "CharacterType.h"
#include "PlayerID.h"

#include "PlayerCollider.h"
#include "iPlayerCollider.h"

#include "iPlayer.h"
#include "iState.h"
#include "iStateMachine.h"

namespace RB::Players
{
	class Player : public iPlayer
	{
	public:
		Player() = default;
		~Player() override;

	public:
		void Init(PlayerID id, RB::States::iState* firstPlayerState) override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		PlayerID GetPlayerID() override;
		void SetCharacterType(CharacterType type) override;
		CharacterType GetCharacterType() override;
		iPlayerCollider* GetPlayerCollider() override;
		int GetPlayerID_int() override;
		bool IsFacingRight() override;
		bool OtherPlayerIsOnRightSide() override;
		bool InitiallyFacingRight();
		void InitiallyFacingRight(bool initiallyFacingRight);
		RB::States::iStateMachine* GetStateMachine() override;
		unsigned int GetStateMachineID() override;
		void Move(olc::vi2d moveAmount) override;
		olc::vi2d GetPosition() override;
		void SetPosition(olc::vi2d pos) override;
		void SetManualAnimationUpdate(bool manual) override;
		bool ManualAnimationUpdate() override;
		void SetWincingStatus(bool wincing) override;
		bool IsWincing() override;
		void FixDirDuringState(bool fix) override;
		void SetIsInSpecialMoveStatus(bool specialMove) override;
		bool IsInSpecialMoveStatus() override;

	protected:
		PlayerID _playerID = PlayerID::NONE;
		CharacterType _characterType = CharacterType::NONE;
		RB::States::iStateMachine* _stateMachine = nullptr;
		PlayerCollider _playerCollider;
		olc::vi2d _position = { 0, 0 };
		bool _manualAnimationUpdate = false;
		bool _initiallyFacingRight = false;
		bool _isWincing = false;
		bool _dirIsFixedDuringState = false;
		bool _isInSpecialMoveState = false;
	};
}