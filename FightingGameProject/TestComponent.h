#pragma once
#include "olcPixelGameEngine.h"
#include "StateComponentBase.h"
#include "iPlayer.h"

namespace RB::States
{
	class TestComponent : public StateComponentBase
	{
	public:
		void OnFixedUpdate() override;
	};
}