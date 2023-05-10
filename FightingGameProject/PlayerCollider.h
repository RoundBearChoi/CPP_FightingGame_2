#pragma once
#include "olcPixelGameEngine.h"
#include "iPlayer.h"
#include "AABB.h"
#include "GameplayControllers.h"

namespace RB::Players
{
	class PlayerCollider
	{
	public:
		PlayerCollider();
		~PlayerCollider();

	public:
		void Init(iPlayer* owner);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		RB::Collisions::AABB GetAABB();
		olc::vi2d GetPlayerBox();
		bool IsColliding();
		void ResolveCollision(iPlayer* otherPlayer);

	private:
		iPlayer* _player = nullptr;
		bool _isColliding = false;
		olc::vi2d _playerBox = { 82, 124 }; //even numbers?
	};
}