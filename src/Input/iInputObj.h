#pragma once

#include "../InfInt.h"

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

		virtual PlayerInput GetPlayerInputType() = 0;
		virtual void SetReleasedStatus(bool released) = 0;
		virtual void SetUsedAsAttack(bool used) = 0;
		virtual void SetUsedAsMovement(bool used) = 0;
		virtual bool IsReleased() = 0;
		virtual bool IsUsedAsAttack() = 0;
		virtual bool IsUsedAsMovement() = 0;
		virtual unsigned int GetFixedUpdateCount() = 0;
		virtual InfInt GetGameFrameCount() = 0;
		virtual bool IsPressedOnSameFrameAs(iInputObj* inputObj) = 0;
		virtual bool IsPressedEarlierThan(iInputObj* inputObj) = 0;
	};
}
