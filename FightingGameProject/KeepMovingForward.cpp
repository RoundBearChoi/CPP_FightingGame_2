#include "KeepMovingForward.h"

namespace RB::PlayerStateComponents
{
	KeepMovingForward::KeepMovingForward()
	{

	}
	KeepMovingForward::~KeepMovingForward()
	{

	}

	void KeepMovingForward::OnEnter()
	{
		_moveForwardDetector.Init(_state->GetOwnerPlayer());
	}

	void KeepMovingForward::OnUpdate()
	{
		_moveForwardDetector.OnUpdate();
	}
}