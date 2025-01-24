#include "GameplayUpdaterSetup.h"

#include "../Players/PlayerController.h"

namespace RB::Updaters
{
    GameplayUpdaterSetup::GameplayUpdaterSetup(UpdaterBase* updater)
    {
        updater->AddController(new Players::PlayerController(), Controllers::ControllerType::PLAYER_CONTROLLER);
        
        Controllers::iController* playerController = updater->GetController(Controllers::ControllerType::PLAYER_CONTROLLER);
        
        Controllers::ControllerType tt = playerController->GetControllerType();
        
        Controllers::iController* c = RB::Controllers::GetController(Controllers::ControllerType::PLAYER_CONTROLLER);
        
        int n = 0;
    }
}