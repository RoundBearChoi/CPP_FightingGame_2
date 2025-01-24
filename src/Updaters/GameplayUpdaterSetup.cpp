#include "GameplayUpdaterSetup.h"

#include "../Players/PlayerController.h"
#include "../Background/BackgroundController.h"
#include "../Render/PlayerDebugController.h"
#include "../Render/PlayerAnimationController.h"
#include "../Collisions/PlayerBoxDataController.h"
#include "../Players/SpecsController.h"
#include "../Input/InputController.h"

namespace RB::Updaters
{
    GameplayUpdaterSetup::GameplayUpdaterSetup(UpdaterBase* updater)
    {
        auto backgroundController = updater->AddController(new Background::BackgroundController(), Controllers::ControllerType::BACKGROUND_CONTROLLER);
        auto playerController = static_cast<Players::iPlayerController*>(updater->AddController(new Players::PlayerController(), Controllers::ControllerType::PLAYER_CONTROLLER));
        auto playerDebugController = updater->AddController(new Render::PlayerDebugController(), Controllers::ControllerType::PLAYER_DEBUG_CONTROLLER);
        auto playerAnimationController = updater->AddController(new Render::PlayerAnimationController(), Controllers::ControllerType::PLAYER_ANIMATION_CONTROLLER);
        auto playerBoxDataController = updater->AddController(new Collisions::PlayerBoxDataController, Controllers::ControllerType::PLAYER_BOX_DATA_CONTROLLER);
        auto specsController = updater->AddController(new Players::SpecsController(), Controllers::ControllerType::SPECS_CONTROLLER);
        auto inputController = updater->AddController(new Input::InputController(), Controllers::ControllerType::INPUT_CONTROLLER);

        int n = 0;
    }
}