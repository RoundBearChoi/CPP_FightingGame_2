#include "PlayerBoxEditorUpdater.h"

#include "../Vector2.h"
#include "../Players/Player.h"

#include "../Players/PlayerController.h"
#include "../Render/PlayerAnimationController.h"
#include "../Collisions/PlayerBoxDataController.h"
#include "../Cam/CamController.h"
#include "../Render/PlayerDebugController.h"
#include "../Input/InputController.h"
#include "../Collisions/PlayerBoxEditController.h"

#include "../Fighter_0_States/F0_Dummy.h"

namespace RB::Updaters
{
	PlayerBoxEditorUpdater::~PlayerBoxEditorUpdater()
	{
		
	}

	void PlayerBoxEditorUpdater::Init()
	{
		AddController(new Render::PlayerAnimationController(), Controllers::ControllerType::PLAYER_ANIMATION_CONTROLLER);
		AddController(new Collisions::PlayerBoxDataController(), Controllers::ControllerType::PLAYER_BOX_DATA_CONTROLLER);
		AddController(new Input::InputController(), Controllers::ControllerType::INPUT_CONTROLLER);
		AddController(new Render::PlayerDebugController(), Controllers::ControllerType::PLAYER_DEBUG_CONTROLLER);
		AddController(new Collisions::PlayerBoxEditController(), Controllers::ControllerType::PLAYER_BOX_EDIT_CONTROLLER);

		auto playerController = static_cast<Players::iPlayerController*>(AddController(new Players::PlayerController(), Controllers::ControllerType::PLAYER_CONTROLLER));
		auto camController = static_cast<Cam::iCamController*>(AddController(new Cam::CamController(), Controllers::ControllerType::CAM_CONTROLLER));
		
		Players::iPlayer* p0 = playerController->AddPlayer(new RB::Players::Player());

		p0->Init(RB::Players::PlayerID::PLAYER_1, new RB::Fighter_0_States::F0_Dummy(RB::Sprites::SpriteType::fighter_0_standup));
		p0->SetPosition(RB::Vector2{ 50.0f, 100.0f });
		p0->SetCharacterType(RB::Players::CharacterType::AKU);
		p0->SetManualAnimationUpdate(true);

		camController->SetZoom(1.0f);

		InitAllControllers();
	}

	void PlayerBoxEditorUpdater::OnUpdate()
	{
		_UpdateControllers();
	}

	void PlayerBoxEditorUpdater::OnFixedUpdate()
	{
		_FixedUpdateControllers();
	}
}