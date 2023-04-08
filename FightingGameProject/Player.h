#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "Time.h"
#include "iStateMachine.h"
#include "StateMachineBase.h"
#include "TestState.h"

using namespace std;
using namespace olc;
using namespace RB::Frames;
using namespace RB::States;

namespace RB::Players
{
	class Player
	{
	public:
		Player();
		~Player();

		void Init(int playerIndex);
		void OnUpdate();
		void OnFixedUpdate();
		vf2d GetPosition();
		void Move(vf2d moveAmount);

	private:
		int _playerIndex = 0;
		iStateMachine* _stateMachine = nullptr;
		vf2d _position = { 0.0f, 0.0f };
	};
}