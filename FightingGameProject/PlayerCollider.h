#pragma once
#include "olcPixelGameEngine.h"
#include "iPlayer.h"
#include "AABB.h"

#include "ControllerGetter.h"
#include "PlayerController.h"

namespace RB::Players
{
	class PlayerCollider
	{
	public:
		PlayerCollider() = default;
		~PlayerCollider() = default;

	public:
		void Init(iPlayer* owner);
		void OnUpdate();
		void OnFixedUpdate();

	public:
		void InitPlayerColliderAABB();
		RB::Collisions::AABB& GetAABB();
		olc::vi2d GetPlayerBox();
		bool IsColliding();
		void ResolveCollision(iPlayer* otherPlayer);

	private:
		//RB::Controllers::ControllerGetter<RB::Players::PlayerController> _getter_playerController;
		iPlayer* _player = nullptr;
		bool _isColliding = false;
		olc::vi2d _playerBox = { 82, 124 }; //even numbers?
		RB::Collisions::AABB _aabb{ 0, 0, 0, 0 };
	};
}