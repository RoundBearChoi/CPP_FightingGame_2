#pragma once

#include "olcPixelGameEngine.h"

#include "iPlayerController.h"

namespace RB::Players
{
	class iPlayerCollider
	{
	public:
		iPlayerCollider() = default;
		virtual ~iPlayerCollider() {};

	public:
		virtual void Init(iPlayer* owner) = 0;
		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;
	};
}