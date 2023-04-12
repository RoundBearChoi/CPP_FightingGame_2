#pragma once
#include "olcPixelGameEngine.h"

namespace RB::Players
{
	class iPlayer;

	class PlayerCollider
	{
	public:
		PlayerCollider();
		~PlayerCollider();

	public:
		void Init(iPlayer* owner);

	private:
		iPlayer* _player = nullptr;
		olc::vi2d _playerBox = { 80, 120 };
	};
}