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
		virtual void SetReleasedStatus(bool released) = 0;
		virtual void SetUsedStatus(bool used) = 0;
		virtual bool IsReleased() = 0;
		virtual bool IsUsed() = 0;
		virtual size_t GetFixedUpdateCount() = 0;
	};
}