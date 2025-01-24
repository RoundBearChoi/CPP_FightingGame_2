#pragma once

namespace RB::Controllers
{
    enum class ControllerType
    {
        NONE,

        PLAYER_CONTROLLER,
        BACKGROUND_CONTROLLER,
        PLAYER_DEBUG_CONTROLLER,
        PLAYER_ANIMATION_CONTROLLER,
        PLAYER_BOX_DATA_CONTROLLER,
        SPECS_CONTROLLER, //player specs controller
        INPUT_CONTROLLER,
    };
}