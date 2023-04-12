#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "Time.h"
#include "iStateMachine.h"
#include "StateMachineBase.h"
#include "StateMachineID.h"
#include "iPlayer.h"
#include "PlayerID.h"
#include "PlayerTestState.h"
#include "PlayerCollider.h"

namespace RB::Players
{
	class Player : public iPlayer
	{
	public:
		Player();
		~Player() override;

	public:
		void Init(PlayerID id);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		olc::vi2d GetPosition() override;
		olc::vi2d GetPlayerBox() override;
		PlayerID GetPlayerID() override;
		int GetStateMachineID() override;
		void Move(olc::vi2d moveAmount) override;
		void SetPosition(olc::vi2d pos) override;

	private:
		PlayerID _playerID = PlayerID::NONE;
		RB::States::iStateMachine* _stateMachine = nullptr;
		PlayerCollider _playerCollider;
		olc::vi2d _playerBox = { 80, 120 };
		olc::vi2d _position = { 0, 0 };
	};
}