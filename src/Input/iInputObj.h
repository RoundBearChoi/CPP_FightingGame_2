#pragma once

#include "../PlayerInput.h"

namespace RB::Input
{
	class iInputObj
	{
	public:
		iInputObj() = default;
		virtual ~iInputObj() = default;

		virtual void OnUpdate() = 0;
		virtual void OnFixedUpdate() = 0;

		virtual PlayerInput GetPlayerInputType() = 0;
		virtual void SetReleasedStatus(bool released) = 0;
		virtual void SetUsedAsSpecial(bool used) = 0;
		virtual void SetUsedAsMovement(bool used) = 0;
		virtual bool IsReleased() = 0;
		virtual bool IsUsedAsSpecial() = 0;
		virtual bool IsUsedAsMovement() = 0;
		virtual unsigned int GetFixedUpdateCount() = 0;
		virtual unsigned int GetGameFrameCount() = 0;
		virtual bool IsPressedOnSameFrameAs(iInputObj* inputObj) = 0;
		virtual bool IsPressedEarlierThan(iInputObj* inputObj) = 0;
	};
}