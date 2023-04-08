#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "Time.h"
#include "iStateMachine.h"
#include "StateMachineBase.h"
#include "TestState.h"
#include "iPlayer.h"

using namespace std;
using namespace olc;
using namespace RB::Frames;
using namespace RB::States;

namespace RB::Players
{
	class Player : public iPlayer
	{
	public:
		Player();
		~Player() override;

		vf2d GetPosition() override;
		int GetIndex() override;
		void Move(vf2d moveAmount) override;

		void Init(int playerIndex);
		void OnUpdate();
		void OnFixedUpdate();

	private:
		int _playerIndex = 0;
		iStateMachine* _stateMachine = nullptr;
		vf2d _position = { 0.0f, 0.0f };
	};
}