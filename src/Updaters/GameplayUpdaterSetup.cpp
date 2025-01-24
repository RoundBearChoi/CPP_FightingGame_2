#include "GameplayUpdaterSetup.h"

#include "../Players/PlayerController.h"
#include "../Background/BackgroundController.h"
#include "../Render/PlayerDebugController.h"

namespace RB::Updaters
{
    GameplayUpdaterSetup::GameplayUpdaterSetup(UpdaterBase* updater)
    {
        updater->AddController(new Background::BackgroundController(), Controllers::ControllerType::BACKGROUND_CONTROLLER);
        updater->AddController(new Players::PlayerController(), Controllers::ControllerType::PLAYER_CONTROLLER);
        updater->AddController(new Render::PlayerDebugController(), Controllers::ControllerType::PLAYER_DEBUG_CONTROLLER);
        
        int n = 0;
    }
}