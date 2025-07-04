#pragma once

#include "../Players/PlayerState.h"
#include "../Sprites/SpriteType.h"
#include "../Render/ManualAnimationUpdater.h"

#include "../Players/iPlayerController.h"

namespace RB::Fighter_0_States
{
	class F0_Dummy : public Players::PlayerState
	{
	public:
		F0_Dummy(Sprites::SPRITE_TYPE startingSpriteType);

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		Render::ManualAnimationUpdater _manualAnimationUpdater;
	};
}
