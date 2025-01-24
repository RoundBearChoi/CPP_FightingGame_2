#include "GameplayUpdaterSetup.h"

#include "../Players/PlayerController.h"
#include "../Background/BackgroundController.h"

namespace RB::Updaters
{
    GameplayUpdaterSetup::GameplayUpdaterSetup(UpdaterBase* updater)
    {
        updater->AddController(new Background::BackgroundController(), RB::Controllers::ControllerType::BACKGROUND_CONTROLLER);
        updater->AddController(new Players::PlayerController(), Controllers::ControllerType::PLAYER_CONTROLLER);
        
        int n = 0;
    }
}