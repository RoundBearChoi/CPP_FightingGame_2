#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "Time.h"
#include "iStateMachine.h"
#include "StateMachineBase.h"
#include "StateMachineID.h"
#include "iPlayer.h"
#include "PlayerTestState.h"

using namespace std;
using namespace olc;
using namespace RB::Frames;

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
		vi2d GetPosition() override;
		int GetPlayerIndex() override;
		int GetStateMachineID() override;
		void Move(vi2d moveAmount) override;

	private:
		int _playerIndex = 0;
		iStateMachine* _stateMachine = nullptr;
		vi2d _position = { 0, 0 };
	};
}