#pragma once
#include "PlayerState.h"
#include "ManualAnimationUpdater.h"
#include "SpriteEnum.h"

#include "iHurtBoxDataController.h"

#include "ActivePlayerStates.h"

namespace RB::PlayerStates
{
	class P0_Dummy : public RB::PlayerStates::PlayerState
	{
	public:
		P0_Dummy(Sprites::SpriteEnum startingSpriteEnum);

	public:
		void OnEnter() override;
		void OnExit() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	private:
		RB::Render::ManualAnimationUpdater _manualAnimationUpdater;
	};
}