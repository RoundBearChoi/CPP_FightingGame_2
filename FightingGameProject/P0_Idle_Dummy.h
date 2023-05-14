#pragma once
#include "StateBase.h"

namespace RB::P0_States
{
	class P0_Idle_Dummy : public RB::States::StateBase
	{
	public:
		P0_Idle_Dummy()
		{
			_spriteID = RB::Sprites::SpriteID::fighter_0_idle;
		}

		~P0_Idle_Dummy() = default;
	};
}