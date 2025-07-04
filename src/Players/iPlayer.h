#pragma once

#include "CharacterType.h"
#include "PlayerType.h"

#include "iPlayerCollider.h"

#include "../States/iStateMachine.h"

namespace RB::Players
{
	class iPlayer
	{
	public:
		iPlayer() = default;
		virtual ~iPlayer() = default;

	public:
		virtual void Init(PLAYER_TYPE id, RB::States::iState* firstPlayerState) = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

	public:
		virtual PLAYER_TYPE GetPLAYER_TYPE() = 0;
		virtual void SetCharacterType(CharacterType type) = 0;
		virtual CharacterType GetCharacterType() = 0;
		virtual iPlayerCollider* GetPlayerCollider() = 0;
		virtual int GetPLAYER_TYPE_int() = 0;
		virtual bool IsFacingRight() = 0;
		virtual bool OtherPlayerIsOnRightSide() = 0;
		virtual bool InitiallyFacingRight() = 0;
		virtual void InitiallyFacingRight(bool facingRight) = 0;
		virtual void MarkCrouching(bool crouching) = 0;
		virtual bool IsCrouching() = 0;
		virtual unsigned int GetStateMachineID() = 0;
		virtual RB::States::iStateMachine* GetStateMachine() = 0;
		virtual void Move(RB::Vector2 moveAmount) = 0;
		virtual RB::Vector2 GetPosition() = 0;
		virtual void SetPosition(RB::Vector2 pos) = 0;
		virtual void SetManualAnimationUpdate(bool manual) = 0;
		virtual bool ManualAnimationUpdate() = 0;
		virtual void SetWincingStatus(bool wincing) = 0;
		virtual bool IsWincing() = 0;
		virtual void FixDirDuringState(bool fix) = 0;
		virtual void SetIsInSpecialMoveStatus(bool specialMove) = 0;
		virtual bool IsInSpecialMoveStatus() = 0;
		virtual void AddHP(int amount) = 0;
		virtual int GetHP() = 0;
	};
}
