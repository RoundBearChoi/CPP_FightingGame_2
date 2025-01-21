#include "GameplayUpdaterSetup.h"

#include "../Players/PlayerController.h"

namespace RB::Updaters
{
    GameplayUpdaterSetup::GameplayUpdaterSetup(UpdaterBase* updater)
    {
        updater->AddController(new Players::PlayerController(), Controllers::ControllerType::PLAYER_CONTROLLER);

        //Players::iPlayerController* playerController = updater->GetController<Players::iPlayerController>(Controllers::ControllerType::PLAYER_CONTROLLER);
    }
}