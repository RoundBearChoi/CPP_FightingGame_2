#pragma once

#include "UpdaterBase.h"

namespace RB::Updaters
{
    class GameplayUpdaterSetup
    {
    public:
        GameplayUpdaterSetup(UpdaterBase* updater);
        ~GameplayUpdaterSetup() = default;
    };
}