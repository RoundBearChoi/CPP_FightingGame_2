#pragma once

#include "olcPixelGameEngine.h"

#include "iPlayerCollider.h"
#include "iPlayer.h"
#include "iPlayerController.h"

#include "AABB.h"

namespace RB::Players
{
	/// <summary>
	/// playerBox is the size of the playerCollider
	/// </summary>
	class PlayerCollider : public iPlayerCollider
	{
	public:
		PlayerCollider() = default;
		~PlayerCollider() = default;

	public:
		void Init(iPlayer* owner);
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		olc::vi2d GetPlayerBox() override;
		bool IsCollidingAgainstOtherPlayer() override;
		RB::Collisions::AABB& UpdateAABBOnPlayerPos() override;
		RB::Collisions::AABB& GetAABB() override;

	public:
		void _InitPlayerColliderAABB();
		void _MovePlayers(iPlayer* otherPlayer);

	private:
		iPlayer* _player = nullptr;
		bool _isCollidingAgainstOtherPlayer = false;
		olc::vi2d _playerBox = { 62, 124 }; //even numbers?
		RB::Collisions::AABB _aabb{ 0, 0, 0, 0 };
		float _bodyRatio[2]{ 0.0f, 0.0f };
	};
}