#pragma once

#include "../Vector2.h"

namespace RB::Cam
{
    extern RB::Vector2 GetRelPos(RB::Vector2 camPos, float zoom, RB::Vector2 worldPos);
}