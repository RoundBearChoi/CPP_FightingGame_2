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
}