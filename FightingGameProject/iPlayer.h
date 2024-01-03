#pragma once
#include "olcPixelGameEngine.h"

#include "CharacterType.h"
#include "PlayerID.h"

#include "iStateMachine.h"
#include "iPlayerCollider.h"

namespace RB::Players
{
	class iPlayer
	{
	public:
		iPlayer() = default;
		virtual ~iPlayer() = default;

	public:
		virtual void Init(PlayerID id, RB::States::iState* firstPlayerState) = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

	public:
		virtual PlayerID GetPlayerID() = 0;
		virtual void SetCharacterType(CharacterType type) = 0;
		virtual CharacterType GetCharacterType() = 0;
		virtual iPlayerCollider* GetPlayerCollider() = 0;
		virtual int GetPlayerID_int() = 0;
		virtual bool IsFacingRight() = 0;
		virtual bool OtherPlayerIsOnRightSide() = 0;
		virtual bool InitiallyFacingRight() = 0;
		virtual void InitiallyFacingRight(bool facingRight) = 0;
		virtual unsigned int GetStateMachineID() = 0;
		virtual RB::States::iStateMachine* GetStateMachine() = 0;
		virtual void Move(olc::vf2d moveAmount) = 0;
		virtual olc::vf2d GetPosition() = 0;
		virtual void SetPosition(olc::vf2d pos) = 0;
		virtual void SetManualAnimationUpdate(bool manual) = 0;
		virtual bool ManualAnimationUpdate() = 0;
		virtual void SetWincingStatus(bool wincing) = 0;
		virtual bool IsWincing() = 0;
		virtual void FixDirDuringState(bool fix) = 0;
		virtual void SetIsInSpecialMoveStatus(bool specialMove) = 0;
		virtual bool IsInSpecialMoveStatus() = 0;
	};
}