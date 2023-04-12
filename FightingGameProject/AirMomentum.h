#pragma once
#include "olcPixelGameEngine.h"
#include "iPlayer.h"

namespace RB::Players
{
	class AirMomentum
	{
	public:
		AirMomentum();
		~AirMomentum();

	public:
		void Init(iPlayer* owner);

	public:
		olc::vf2d GetMomentum();

	private:
		iPlayer* _player = nullptr;
		olc::vf2d _momentum = { 0.0f, 0.0f };
	};
}