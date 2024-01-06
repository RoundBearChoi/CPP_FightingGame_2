#pragma once
#include "PlayerState.h"

#include "SpriteType.h"
#include "ManualAnimationUpdater.h"

namespace RB::PlayerStates::Aku
{
	class P0_Dummy : public RB::PlayerStates::PlayerState
	{
	public:
		P0_Dummy(Sprites::SpriteType startingSpriteType);

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		RB::Render::ManualAnimationUpdater _manualAnimationUpdater;
	};
}