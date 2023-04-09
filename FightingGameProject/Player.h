#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "Time.h"
#include "iStateMachine.h"
#include "StateMachineBase.h"
#include "StateMachineID.h"
#include "iPlayer.h"
#include "PlayerTestState.h"

namespace RB::Players
{
	class Player : public iPlayer
	{
	public:
		Player();
		~Player() override;

	public:
		void Init(int playerIndex);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		olc::vi2d GetPosition() override;
		int GetPlayerIndex() override;
		int GetStateMachineID() override;
		void Move(olc::vi2d moveAmount) override;

	private:
		int _playerIndex = 0;
		RB::States::iStateMachine* _stateMachine = nullptr;
		olc::vi2d _position = { 0, 0 };
	};
}