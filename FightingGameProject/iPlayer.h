#pragma once
#include "olcPixelGameEngine.h"

#include "AABB.h"
#include "SpriteEnum.h"

#include "iStateMachine.h"
#include "iState.h"

#include "PlayerID.h"

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
		virtual int GetPlayerID_int() = 0;
		virtual bool IsFacingRight() = 0;
		virtual bool OtherPlayerIsOnRightSide() = 0;
		virtual bool InitiallyFacingRight() = 0;
		virtual void InitiallyFacingRight(bool facingRight) = 0;
		virtual size_t GetStateMachineID() = 0;
		virtual RB::States::iStateMachine* GetStateMachine() = 0;
		virtual void Move(olc::vi2d moveAmount) = 0;
		virtual olc::vi2d GetPosition() = 0;
		virtual void SetPosition(olc::vi2d pos) = 0;
		virtual void SetManualAnimationUpdate(bool manual) = 0;
		virtual bool ManualAnimationUpdate() = 0;
		virtual void SetWincingStatus(bool wincing) = 0;
		virtual bool IsWincing() = 0;

	public:
		virtual olc::vi2d GetPlayerBox() = 0;
		virtual RB::Collisions::AABB& UpdateAABBOnPlayerPos() = 0;
		virtual bool IsCollidingAgainstOtherPlayer() = 0;
	};
}