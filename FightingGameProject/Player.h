#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "Time.h"
#include "StateMachineBase.h"
#include "ActiveStateMachines.h"
#include "P0_Start.h"
#include "PlayerCollider.h"
#include "AABB.h"

#include "iPlayerController.h"
#include "iPlayer.h"
#include "PlayerID.h"

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
		int GetPlayerID_int() override;
		bool IsFacingRight() override;
		bool OtherPlayerIsOnRightSide() override;
		bool InitiallyFacingRight();
		void InitiallyFacingRight(bool initiallyFacingRight);
		RB::States::iStateMachine* GetStateMachine() override;
		size_t GetStateMachineID() override;
		void Move(olc::vi2d moveAmount) override;
		olc::vi2d GetPosition() override;
		void SetPosition(olc::vi2d pos) override;
		void SetManualAnimationUpdate(bool manual) override;
		bool ManualAnimationUpdate() override;
		void SetWincingStatus(bool wincing) override;
		bool IsWincing() override;

	public:
		olc::vi2d GetPlayerBox() override;
		RB::Collisions::AABB& UpdateAABBOnPlayerPos() override;
		bool IsCollidingAgainstOtherPlayer() override;

	protected:
		PlayerID _playerID = PlayerID::NONE;
		RB::States::iStateMachine* _stateMachine = nullptr;
		PlayerCollider _playerCollider;
		olc::vi2d _position = { 0, 0 };
		bool _manualAnimationUpdate = false;
		bool _initiallyFacingRight = false;
		bool _isWincing = false;
	};
}