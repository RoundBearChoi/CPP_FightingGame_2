#include "AirMomentum.h"

namespace RB::Players
{
	AirMomentum::AirMomentum()
	{

	}

	AirMomentum::~AirMomentum()
	{

	}

	void AirMomentum::Init(iPlayer* owner)
	{
		_player = owner;
	}

	void AirMomentum::SetMomentum(olc::vf2d momentum)
	{
		_momentum = momentum;
	}

	void AirMomentum::AddMomentum(olc::vf2d momentum)
	{
		_momentum += momentum;
	}

	olc::vf2d AirMomentum::GetMomentum()
	{
		return _momentum;
	}
}