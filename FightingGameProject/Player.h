#pragma once
#include <iostream>
#include "olcPixelGameEngine.h"
#include "Time.h"
#include "iStateMachine.h"
#include "iPlayer.h"
#include "StateMachineBase.h"
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
		vf2d GetPosition() override;
		int GetIndex() override;
		void Move(vf2d moveAmount) override;

	private:
		int _playerIndex = 0;
		iStateMachine* _stateMachine = nullptr;
		vf2d _position = { 0.0f, 0.0f };
	};
}