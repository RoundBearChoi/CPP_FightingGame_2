#pragma once

#include "Players/PlayerState.h"
#include "Sprites/SpriteType.h"
#include "Render/ManualAnimationUpdater.h"

#include "Players/iPlayerController.h"

namespace RB::Fighter_0_States
{
	class P0_Dummy : public RB::Players::PlayerState
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
