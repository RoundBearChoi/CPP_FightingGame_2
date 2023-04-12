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
#include "AABB.h"
#include "AirMomentum.h"

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
		PlayerID GetPlayerID() override;
		int GetStateMachineID() override;
		void Move(olc::vi2d moveAmount) override;
		olc::vi2d GetPosition() override;
		void SetPosition(olc::vi2d pos) override;

	public:
		olc::vi2d GetPlayerBox() override;
		RB::Collisions::AABB GetAABB() override;
		bool IsCollidingAgainstOtherPlayer() override;

	public:
		void SetAirMomentum(olc::vf2d momentum) override;
		olc::vf2d GetAirMomentum() override;

	private:
		PlayerID _playerID = PlayerID::NONE;
		RB::States::iStateMachine* _stateMachine = nullptr;
		PlayerCollider _playerCollider;
		AirMomentum _airMomentum;
		olc::vi2d _position = { 0, 0 };
	};
}