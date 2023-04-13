#pragma once
#include "iGameplayAnimationController.h"

namespace RB::Animations
{
	class GameplayAnimationController : public iGameplayAnimationController
	{
	public:
		GameplayAnimationController();
		~GameplayAnimationController();

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
	};
}