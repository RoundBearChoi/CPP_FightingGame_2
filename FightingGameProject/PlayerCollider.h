#pragma once
#include "olcPixelGameEngine.h"
#include "AABB.h"

#include "iPlayerCollider.h"
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
		void Init(iPlayer* owner) override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		olc::vi2d GetPlayerBox();
		bool IsColliding();
		void ResolveCollision(iPlayer* otherPlayer);

	public:
		void _InitPlayerColliderAABB();
		RB::Collisions::AABB& _UpdateAABBOnPlayerPos();

	private:
		iPlayer* _player = nullptr;
		bool _isColliding = false;
		olc::vi2d _playerBox = { 62, 124 }; //even numbers?
		RB::Collisions::AABB _aabb{ 0, 0, 0, 0 };
		float_t _bodyRatio[2]{ 0.0f, 0.0f };
	};
}