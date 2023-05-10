#pragma once
#include "olcPixelGameEngine.h"
#include "iPlayer.h"

namespace RB::Players
{
	class AirMomentum
	{
	public:
		AirMomentum() = default;
		~AirMomentum() = default;

	public:
		void Init(iPlayer* owner);

	public:
		void SetMomentum(olc::vf2d momentum);
		void AddMomentum(olc::vf2d momentum);
		olc::vf2d GetMomentum();

	private:
		iPlayer* _player = nullptr;
		olc::vf2d _momentum = { 0.0f, 0.0f };
	};
}