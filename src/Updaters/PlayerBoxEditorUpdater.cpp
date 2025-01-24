#include "PlayerBoxEditorUpdater.h"

namespace RB::Updaters
{
	PlayerBoxEditorUpdater::~PlayerBoxEditorUpdater()
	{
		RB::Controllers::ControllerBase::DestroyAllControllers();
	}

	void PlayerBoxEditorUpdater::Init()
	{
		AddController(new Players::PlayerController(), Controllers::ControllerType::PLAYER_CONTROLLER);

		Players::iPlayerController* playerController = GET_PLAYER_CONTROLLER; //RB::Controllers::ControllerBase::AddController<RB::Players::PlayerController>(new RB::Players::PlayerController());
		
		playerController->Init();
		
		Players::iPlayer* p0 = playerController->AddPlayer(new RB::Players::Player());

		p0->Init(RB::Players::PlayerID::PLAYER_1, new RB::Fighter_0_States::F0_Dummy(RB::Sprites::SpriteType::fighter_0_standup));
		p0->SetPosition(RB::Vector2{ 50.0f, 100.0f });
		p0->SetCharacterType(RB::Players::CharacterType::AKU);
		p0->SetManualAnimationUpdate(true);





		AddController(new Render::PlayerAnimationController(), Controllers::ControllerType::PLAYER_ANIMATION_CONTROLLER);
		AddController(new Collisions::PlayerBoxDataController(), Controllers::ControllerType::PLAYER_BOX_DATA_CONTROLLER);
		AddController(new Input::InputController(), Controllers::ControllerType::INPUT_CONTROLLER);
		AddController(new Render::PlayerDebugController(), Controllers::ControllerType::PLAYER_DEBUG_CONTROLLER);

		Controllers::ControllerBase::AddController<RB::Collisions::PlayerBoxEditController>(new RB::Collisions::PlayerBoxEditController());

		Cam::CamController* camController = RB::Controllers::ControllerBase::AddController<RB::Cam::CamController>(new RB::Cam::CamController());
		camController->SetZoom(1.0f);

		InitAllControllers();
	}

	void PlayerBoxEditorUpdater::OnUpdate()
	{
		_UpdateControllers();

		RB::Controllers::ControllerBase::UpdateAll();
	}

	void PlayerBoxEditorUpdater::OnFixedUpdate()
	{
		_FixedUpdateControllers();

		RB::Controllers::ControllerBase::FixedUpdateAll();
	}
}