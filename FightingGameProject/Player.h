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
		PlayerID GetPlayerID() override;
		int GetStateMachineID() override;
		void Move(olc::vi2d moveAmount) override;

	private:
		PlayerID _playerID = PlayerID::NONE;
		RB::States::iStateMachine* _stateMachine = nullptr;
		olc::vi2d _position = { 0, 0 };
	};
}