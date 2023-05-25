#pragma once
#include "olcPixelGameEngine.h"
#include "ControllerBase.h"

#include "ActivePlayerStates.h"

#include "ControllerGetter.h"
#include "SpriteDataController.h"
#include "PlayerController.h"
#include "PlayerAnimationController.h"
#include "HurtBoxDataController.h"

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

	private:
		const std::string& _GetCurrentSpriteString();
		RB::Sprites::SpriteEnum _GetCurrentSpriteEnum();
		int32_t _GetCurrentAnimationFrame();
		size_t _GetAABBCount();

	private:
		RB::Controllers::ControllerGetter<RB::Sprites::SpriteDataController> _getter_sprDataController;
		RB::Controllers::ControllerGetter<RB::Players::PlayerController> _getter_playerController;
		RB::Controllers::ControllerGetter<RB::Render::PlayerAnimationController> _getter_pAniController;
		RB::Controllers::ControllerGetter<RB::HurtBox::HurtBoxDataController> _getter_hurtBoxDataController;

	private:
		RB::Sprites::SpriteEnum _currentSpriteEnum = RB::Sprites::SpriteEnum::NONE;
		const std::string _none = "NONE";
	};
}