#pragma once

#include "iPlayerCollider.h"
#include "iPlayer.h"
#include "iPlayerController.h"

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
		bool IsColliding() override;
		RB::Collisions::AABB& UpdateAABBOnPlayerPos() override;

	public:
		void _InitPlayerColliderAABB();
		void _ResolveCollision(iPlayer* otherPlayer);

	private:
		iPlayer* _player = nullptr;
		bool _isColliding = false;
		olc::vi2d _playerBox = { 62, 124 }; //even numbers?
		RB::Collisions::AABB _aabb{ 0, 0, 0, 0 };
		float_t _bodyRatio[2]{ 0.0f, 0.0f };
	};
}