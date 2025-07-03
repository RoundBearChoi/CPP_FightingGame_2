#include "HBoxEditorUpdaterBase.h"

#include "../Input/InputController.h"
#include "../Cam/CamController.h"
#include "../Players/PlayerController.h"
#include "../Render/PlayerDebugController.h"
#include "../Render/PlayerAnimationController.h"
#include "../Collisions/PlayerBoxDataController.h"
#include "../HBox/HBMenuController.h"
#include "../HBox/TargetBoxDataController.h"
#include "../HBox/AttackBoxDataController.h"
#include "../HBox/HBoxEditController.h"

namespace RB::Updaters
{
	HBoxEditorUpdaterBase::HBoxEditorUpdaterBase()
	{

	}

	HBoxEditorUpdaterBase::~HBoxEditorUpdaterBase()
	{
		
	}

	void HBoxEditorUpdaterBase::Init()
	{
		AddController(new Render::PlayerAnimationController(), Controllers::ControllerType::PLAYER_ANIMATION_CONTROLLER);
		AddController(new Collisions::PlayerBoxDataController(), Controllers::ControllerType::PLAYER_BOX_DATA_CONTROLLER);
		AddController(new Input::InputController(), Controllers::ControllerType::INPUT_CONTROLLER);
		AddController(new Render::PlayerDebugController(), Controllers::ControllerType::PLAYER_DEBUG_CONTROLLER);
		AddController(new HBox::HBoxEditController(_boxType), Controllers::ControllerType::HBOX_EDIT_CONTROLLER);
		AddController(new Players::PlayerController(), Controllers::ControllerType::PLAYER_CONTROLLER);

		if (_boxType == HBox::HBoxType::TARGET_BOX)
		{
			AddController(new HBox::TargetBoxDataController(_specsPath), Controllers::ControllerType::TARGET_BOX_DATA_CONTROLLER);
		}
		else if (_boxType == HBox::HBoxType::ATTACK_BOX)
		{
			AddController(new HBox::AttackBoxDataController(_specsPath), Controllers::ControllerType::ATTACK_BOX_DATA_CONTROLLER);
		}

		auto hbMenuController = static_cast<HBox::iHBMenuController*>(AddController(new HBox::HBMenuController(), Controllers::ControllerType::HB_MENU_CONTROLLER));
		auto camController = static_cast<Cam::iCamController*>(AddController(new Cam::CamController(), Controllers::ControllerType::CAM_CONTROLLER));

		hbMenuController->SetPageTitle(_pageTitle);
		
		camController->SetZoom(1.0f);

		_InitAllControllers();
	}

	void HBoxEditorUpdaterBase::OnUpdate()
	{
		_UpdateAllControllers();
	}

	void HBoxEditorUpdaterBase::OnFixedUpdate()
	{
		_FixedUpdateAllControllers();
	}
}
