#pragma once
#include "olcPixelGameEngine.h"
#include "iPlayer.h"
#include "AABB.h"

namespace RB::Players
{
	class PlayerCollider
	{
	public:
		PlayerCollider();
		~PlayerCollider();

	public:
		void Init(iPlayer* owner);
		RB::Collisions::AABB GetAABB();
		olc::vi2d GetPlayerBox();

	private:
		iPlayer* _player = nullptr;
		olc::vi2d _playerBox = { 80, 120 };
	};
}