#pragma once
#include "olcPixelGameEngine.h"
#include "ControllerBase.h"

#include "ActivePlayerStates.h"

#include "ControllerGetter.h"
#include "SpriteDataController.h"
#include "PlayerController.h"
#include "PlayerAnimationController.h"

namespace RB::HurtBox
{
	class MenuController : public RB::Controllers::ControllerBase
	{
	public:
		MenuController();
		~MenuController() override {};

	public:
		void Init() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;

	public:
		RB::Sprites::SpriteEnum GetCurrentSpriteEnum();
		const std::string& GetCurrentSpriteString();
		int32_t GetCurrentFrame();

	private:
		RB::Controllers::ControllerGetter<RB::Sprites::SpriteDataController> _getter_sprDataController;
		RB::Controllers::ControllerGetter<RB::Players::PlayerController> _getter_playerController;
		RB::Controllers::ControllerGetter<RB::Render::PlayerAnimationController> _getter_pAniController;
		RB::Sprites::SpriteEnum _currentSpriteEnum = RB::Sprites::SpriteEnum::NONE;
		const std::string _none = "NONE";
	};
}