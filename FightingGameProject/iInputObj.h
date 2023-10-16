#pragma once
#include "olcPixelGameEngine.h"
#include "PlayerInput.h"

namespace RB::Input
{
	class iInputObj
	{
	public:
		iInputObj() = default;
		virtual ~iInputObj() = default;

		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual PlayerInput GetPlayerInput() = 0;
		virtual olc::Key GetKey() = 0;
		virtual void SetReleasedStatus(bool released) = 0;
	};
}