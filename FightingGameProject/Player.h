#pragma once
#include <iostream>
#include "Time.h"
#include "iStateMachine.h"
#include "StateMachineObj.h"
#include "TestState.h"

using namespace std;
using namespace RB::Frames;
using namespace RB::States;

namespace RB::Players
{
	class Player
	{
	private:
		int _playerIndex = 0;
		iStateMachine* _stateMachine = nullptr;

	public:
		Player();
		~Player();

		void Init(int playerIndex);
		void OnUpdate();
		void OnFixedUpdate();
	};
}