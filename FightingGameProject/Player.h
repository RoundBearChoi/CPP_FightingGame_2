#pragma once
#include <iostream>
#include "Time.h"
#include "iStateMachine.h"
#include "StateMachineObj.h"
#include "TestState.h"

using namespace std;
using namespace RB::Frames;

namespace RB::Players
{
	class Player
	{
	private:
		int _playerIndex = 0;
		StateMachine::iStateMachine* _stateMachine = nullptr;

	public:
		Player();
		~Player();

		void Init(int playerIndex);
		void OnUpdate();
		void OnFixedUpdate();
	};
}